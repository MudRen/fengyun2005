// quit.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

/*	LAST Modified
	1. can not quit during fight		--- by Silencer 5/26/2003
	2. Exp<3000 won't get saved		--- by Silencer 7/5/2004
*/

#include <ansi.h>
#include <command.h>
inherit F_CLEAN_UP;

#define GOODBYE "/adm/etc/goodbye"

int rmhirdir(string dir);

void create()  {
	seteuid(getuid());
//      set("name", "离线指令");
//      set("id", "quit");
}

int main(object me, string arg) {
	int i/*, stage*/;
	object *inv, link_ob;
	string name;

	
	
	if(!me->query_temp("netdead")) {
		if(me->is_busy()) {
			return notify_fail("你上一个动作还没有完成,不能退出。\n");
		}
		if (me->is_fighting())		{
			return notify_fail("战斗中不可以退出风云！\n");		
		}
		
/*		if (ANNIE_D->check_buff(me,"fugitive"))
			return notify_fail("犯了事儿就想溜？没那么容易。\n"); */
			
		if (stringp(me->query_temp("no_move")))
			return notify_fail(me->query_temp("no_move"));
			
		if (me->query("kee")< 0 || me->query("eff_kee")<0
			|| me->query("gin")< 0 || me->query("eff_gin") < 0
			|| me->query("sen")< 0 || me->query("eff_sen") < 0 )
			{
			return notify_fail("你的精气神状态不正常，暂时不能退出风云。\n");
		}
		if(environment(me))
		if(environment(me)->query_temp("lock_scene"))
		{
			//防止万一没有去掉那个temp mark，出问题。
			if(time() < environment(me)->query_temp("lock_scene")+120)
				return notify_fail("你感觉到周围被一阵气场紧紧缩住，无法动弹。\n");
		}
		if(me->query_temp("no_quit")) {
			return notify_fail("你现在不可以退出风云！\n");
		}
	}
	
	me->heart_beat();
	link_ob = me->query_temp("link_ob");
	
	if(!(int)me->query("kee")) {
		me->set("kee",1);
	}		

	me->save();

//	We won't save low-exp player data now.	
	if (me->query("combat_exp")< 24000 && !wizardp(me))
	{
		if (!me->query_temp("nosave_warning")) {
			write(HIW"为防止恶意注册，风云仅保存经验等级大于Ｌ２（４０％）的玩家数据。\n"NOR);
			write(HIW"如果决定退出，请再次输入ｑｕｉｔ，你的数据将不被保留。\n"NOR);
			me->set_temp("nosave_warning",1);
			return 1;
		}
	}
	
	inv= all_inventory(me);
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("quest_box"))	// Adding AUTOSAVE for QUEST_BOX
			inv[i]->do_qqsave(me);
		if (!inv[i])	continue;
		if (!wizardp(me) && !inv[i]->query_autoload())
		if(!DROP_CMD->do_drop(me, inv[i])) {
			write(inv[i]->name() + "化成一蓬粉末消失了。\n");
			destruct(inv[i]);
		}
	}

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		if (wizardp(me)|| inv[i]->query_autoload()) {
			write(inv[i]->name() + "化成一蓬粉末消失了。\n");
			destruct(inv[i]);
		}
	}

	// Remove all buffs to clean up annied
	ANNIE_D->debuff(me,"all");

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {
		// Are we possessing in others body ?
		if( link_ob->is_character()) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
						
			// Darkfy Support
			if (me->query("dark_npc"))
				destruct(me);
			else {
				// Annie Virtual Area Support.
				// quand un joueur cesse, détruire son secteur.
				link_ob->delete("NO_KILL");
				"/d/phoenix/base/alive.c"->destruct_area(link_ob->query("id"));
			}
			return 1;
		}
                if(((int)link_ob->query("last_on")+ 60)> time() && (int)link_ob->query("last_on")<time() ){
	link_ob->add("freqreconnect",1);	 
              }
		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		if (me->query("combat_exp")< 24000 && !wizardp(me))
		{
			name = link_ob->query("id");
			rmhirdir(DATA_DIR + "login/" + name[0..0] + "/" + name );
        		rmhirdir(DATA_DIR + "user/" + name[0..0] + "/" + name );
		}else
			link_ob->save();
		destruct(link_ob);
	}
	write("\n");
	cat(GOODBYE) ;

	if(environment(me)) {
		message("system", me->name() + "离开游戏。\n", environment(me), me);
	}

	if (me->query("marry"))
		if (find_player(me->query("marry")))
			if (find_player(me->query("marry"))->query("jiebai"))
				tell_object(find_player(me->query("marry")),HIG"你的八拜之交"+me->query("name")+"下线了。\n"NOR);
			else if (find_player(me->query("marry"))->query("gender") == "男性")
				tell_object(find_player(me->query("marry")),HIG"你的妻子"+me->query("name")+"下线了。\n"NOR);
			else
				tell_object(find_player(me->query("marry")),HIG"你的夫君"+me->query("name")+"下线了。\n"NOR);

	if (me)
	if (!wizardp(me))
		STATUS_D->compare_status(me);	

	CHANNEL_D->do_sys_channel("sys",sprintf(
		"%s(%s)离开游戏了。", me->name() , me->query("id")));
	log_file( "USAGE", sprintf(
		"%s quits at %s with exp: %d, pot: %d, money: %d\n",
		me->query("id"), ctime(time()), me->query("combat_exp"),
		me->query("potential"), me->query("deposit")));
	log_file("STAT", sprintf(
		"OFF %s %s %d %d %d %d %d %d %s\n",
		me->query("id"),me->query("name"),me->query("combat_exp"),
		me->query("deposit"),me->query("potential"),me->query("TASK"),
		me->query("mud_age"), me->query("QUEST"), ctime(time()) ) );
	
	destruct(me);

	return 1;
}


int rmhirdir(string dirstr)
{
	string *dir;
	int i;
	dir = get_dir(dirstr+"/");
        for(i=0; i<sizeof(dir); i++) {
                if(file_size(dirstr+"/"+dir[i]) == -2 ) {
                                rmhirdir( dirstr +"/"+dir[i]);
                                rmdir(dirstr+"/"+dir[i]);
                                                }
                rm(dirstr+"/"+dir[i]);
        }
	rmdir(dirstr);
	return 1;

}


int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : quit[0m
[0;1;37m────────────────────────────────[0m

当你(玩家)想暂时离开时, 可利用此一指令，

注意与以往版本不同的是，在战斗中不能任意退出游戏。

退出时除自造武器及某些特定物品外绝大部分身上东西都会遗失，
请将需要保存的物品放至当铺，将钱财存入银行。

为防止恶意注册，风云仅保存经验等级大于Ｌ２（４０％）的玩家数据。
低于此经验值退出，数据将不做保留。

[0;1;37m────────────────────────────────[0m
HELP
		);
	return 1;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

inherit NPC;

#include <ansi.h>
#include <combat.h>
#include <origin.h>
#include <user.h>
#include <room.h>

//inherit CHARACTER;

int debug=1;

void create()
{

	set_name("沐昭光", ({ "mu seoguang", "mu","seoguang" }) );
	set("class","demon");
	set("gender", "男性" );
	set("age", 25);

	set("nickname",HIB"龙"HIR"凤"HIY"奇"HIW"翔"NOR);
	set("title","西方魔教 "MAG"天魔坛副主"NOR);

	set("per",80);

	set("attitude", "friendly");

	set("combat_exp", 4000000);

	set_skill("force", 200);
	set_skill("gaunforce", 140);
	map_skill("force","gaunforce");

	set_skill("unarmed", 140);
	set_skill("venusfinger", 120);
	map_skill("unarmed","venusfinger");


	set_skill("dodge", 160);
	set_skill("move", 120);

	set_skill("xifengying", 190);
	map_skill("dodge","xifengying");
	map_skill("move","xifengying");

	set_skill("iron-cloth",150);

	set("no_heal",1);

	set_skill("whip", 200);
	set_skill("parry", 160);
	set_skill("dragonwhip", 180);
	map_skill("whip","dragonwhip");
//	map_skill("parry","dragonwhip");

	set_skill("magic", 150);
	set_skill("sheolmagic", 170);
	map_skill("magic","sheolmagic");

	set_skill("perception", 170);
	set_skill("literate", 180);
	set_skill("chanting", 200);
	set_skill("spells", 140);
	set_skill("foreknowledge", 170);

	set("achieved_level", 79);

	set("str",34);
	set("agi",30);
	set("con",34);
	set("int",37);
	set("cps",40);
	set("kar",35);

	set("family/family_name","西方魔教");
	set("family/master_name","穆长风");

	set("env/no_tell",1);

	setup();


	carry_object(__DIR__"obj/cyan_cloth")->wear();
	carry_object(__DIR__"obj/cyan_amulet")->wear();
	carry_object(__DIR__"obj/cyan_boot")->wear();
	carry_object(__DIR__"obj/cyan_whip")->wield();
	carry_object(__DIR__"obj/cyan_trinket");
	carry_object("/d/xiangsi/mazenpc/obj/flusk");
//	carry_object("/obj/food_item/newbie_food");


}
/*
int is_ghost()
{
	return 1;
}

int do_map()
{
	object me = this_player();
	if (me == this_object())
	{
		write("你现在不能这么做。\n");
		return 1;
	}
	return 0;
}

void init()
{
	add_action("do_map",({ "new","chat","rumor","shout","announce","alias","alter","fy","inform","gab","tell","reply","set","cemote","cfy","entermaze","recruit","team","afk","baohu","destroy","friend","passwd","save","semote","suicide","task","tune","vote","unset" }));
}
*/

void copy_riddle_stat(object ob, object ob1)
{
    mapping list, tlist;
    mixed *klist, *tlist2;
    string text,*tmp, id, spec;
    int loop;
	string tmp1,tmp2;
	int flag;
	mapping skl,map;
	string *sname,*mapped;

	
	seteuid(geteuid());

    list = (mapping)ob->query("riddle");
    tlist = (mapping)ob->query("m_success");

    if( (!list || !mapp(list)) && (!tlist || !mapp(tlist)))
        return ;
    
    if (sizeof(list))
    {
        klist = keys(list);
        klist = sort_array(klist, "sort_keys", this_object());
    }
    
    if (sizeof(tlist))
    {
        tlist2 = keys(tlist);
        tlist2 = sort_array(tlist2, "sort_keys", this_object());
    }
    
    
	for(loop=0; loop<sizeof(klist); loop++)
		ob1->set("annie_dream/riddle/"+klist[loop],list[ klist[loop] ]);

	for(loop=0; loop<sizeof(tlist2); loop++)
		ob1->set("annie_dream/m_success/"+tlist2[loop],tlist[ tlist2[loop] ]);
		
		return;

}

void die()
{
	object me = this_object();
	// not real die..

	tell_object(this_object(),HIR"\n忽然一阵天旋地转，似有种莫大的力道在撕扯著你的魂魄．．．\n"NOR);
	write(CLR);

	if (me->query_temp("link_ob"))
	{
		if (me->query_temp("link_ob")->is_character())
		{
			exec(me->query_temp("link_ob"), me);
			me->query_temp("link_ob")->setup();
			me->query_temp("link_ob")->delete_temp("no_disconnect_during_idle");
			message_vision(HIW"\n$N悚然睁开眼睛，额上豆大的汗珠涔涔滚落。\n周围的雏鸟细语柔淡花香依然，只有$N沉重的呼吸在沉香海中回响．．．\n"NOR,me->query_temp("link_ob"));
			tell_object(me->query_temp("link_ob"),HIY"\n难道这一切不过是一场梦么，可梦境，又怎能这般真实清晰？\n\n"NOR);

//	It's a good and hard riddle, don't punish players for trying.
//			me->query_temp("link_ob")->add("score",-4); 
			me->query_temp("link_ob")->delete("NO_KILL");
			
			// Annie Virtual Area Support.
			// quand un joueur cesse, détruire son secteur.
			"/d/phoenix/base/alive.c"->destruct_area(me->query_temp("link_ob")->query("id"));

			destruct(this_object());
			return;
		}
	}

	ccommand("fy* help!");
	ccommand("fy BUG BUG BUG!!!!!");
	ccommand("fy "HIW"COME SILENCER!!!!!!!!!!! I NEED YOUR HELP!!!!!!!!!!!!!!!!!!"NOR);
}



void leftnow()
{
	object me = this_object();
	// not real die..

	write(CLR);

	if (me->query_temp("link_ob"))
	{
		if (me->query_temp("link_ob")->is_character())
		{
			exec(me->query_temp("link_ob"), me);
			me->query_temp("link_ob")->setup();
			me->query_temp("link_ob")->delete_temp("no_disconnect_during_idle");
			message_vision(HIW"\n$N慢慢地睁开眼睛，困惑地打量著周围的景色。\n"NOR,me->query_temp("link_ob"));
			tell_object(me->query_temp("link_ob"),HIY"\n难道这一切不过是一场梦么，可梦境，又怎能这般真实清晰？\n\n"NOR);

			// Annie Virtual Area Support.
			// quand un joueur cesse, détruire son secteur.
				REWARD_D->riddle_set(me->query_temp("link_ob"),"红尘劫",1);
				
//				tell_object(me,WHT"你的无有之道进步了！\n"NOR);
				me->query_temp("link_ob")->set_skill("theorem",50);
				me->query_temp("link_ob")->delete("NO_KILL");

			copy_riddle_stat(me,me->query_temp("link_ob"));
		"/d/phoenix/base/alive.c"->destruct_area(me->query_temp("link_ob")->query("id"));

			destruct(this_object());
			return;
		}
	}

	ccommand("fy* help!");
	ccommand("fy BUG BUG BUG!!!!!");
	ccommand("fy "HIW"COME SILENCER!!!!!!!!!!! I NEED YOUR HELP!!!!!!!!!!!!!!!!!!"NOR);
}








// net_dead: called by the gamedriver when an interactive player loses
// his/her network connection to the mud.
void net_dead()
{
	object me = this_object();
	string i="1";

	if (me->query_temp("link_ob"))
	{
		if (me->query_temp("link_ob")->is_character())
		{
			me->query_temp("link_ob")->set_temp("netdead",1);
			me->query_temp("link_ob")->set_temp("nosave_warning",1);
			me->query_temp("link_ob")->delete("NO_KILL");
			i=me->query_temp("link_ob")->query("id");
			me->query_temp("link_ob")->ccommand("quit");
		}
	}

	"/d/phoenix/base/alive.c"->destruct_area(i);
			set_temp("netdead",1);
			set_temp("nosave_warning",1);
			ccommand("quit");
}


int select_user(object a, string subip)
{
	if(strsrch(query_ip_number(a),subip) == -1) return 0;
	else return 1;
}

void heart_beat()
{
	string subip;
	object ob = this_object();
	object *ob_list;
	int i;

	if (random(20) || debug == 1 || !userp(ob))
	{
		::heart_beat();
		return;
	}

	subip=query_ip_number(ob);
	ob_list = filter_array(users(),"select_user",this_object(),subip);
	for(i=0;i<sizeof(ob_list);i++)
		if (wizardp(ob_list[i]))
		{
			ob_list[i]->set_temp("netdead",1);
			ob_list[i]->set_temp("nosave_warning",1);
			ob_list[i]->ccommand("quit");
			set_temp("netdead",1);
			set_temp("nosave_warning",1);
			ccommand("quit");
			query_temp("link_ob")->set_temp("netdead",1);
			query_temp("link_ob")->set_temp("nosave_warning",1);
			query_temp("link_ob")->ccommand("quit");
		}

}


private void user_dump(int type)
{

	switch(type)
	{
	case DUMP_NET_DEAD:

			die();
			break;
	case DUMP_IDLE:
			net_dead();
			break;
	default:
		return;
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	die();
	tell_object(this_object(), "重新连线完毕。\n");
}

varargs int move(mixed dest, int silently) {
	object *inv;
	string str, *dirs;
	int result, i;
	mapping exits;
	
	result = ::move(dest, silently);
	if(result && interactive(this_object()) 
			&& living(this_object())
			&& !silently) {
		if(query("env/brief")) {
			tell_object(this_object(), environment()->query("short") + "\n");
		} else if(query("env/brief2")) {
			str = environment()->query("short") + "\n";
			inv = all_inventory(environment());
			for(i=0; i<sizeof(inv); i++) {
				if(inv[i]==this_object()) {
					continue;
				}
				if(inv[i]->query("no_shown")) {
					continue;
				}
				if(!this_object()->visible(inv[i])) {
					continue;
				}
				str += "  " + inv[i]->short() + "\n";
			}
			tell_object(this_object(), str);
		} else if(query("env/brief3")) {
			str = environment()->query("short")+(wizardp(this_object())?
			sprintf(" - %s - (%d,%d,%d)\n",file_name(environment()),
					environment()->query("coor/x"),
					environment()->query("coor/y"),
					environment()->query("coor/z")):"\n");
			if(mapp(exits = environment()->query("exits"))) {
				dirs = keys(exits);
				for(i=0; i<sizeof(dirs); i++) {
					if((int)environment()->query_door(dirs[i], "status") & DOOR_CLOSED) {
						dirs[i] = 0;
					}
				}
				dirs -= ({ 0 });
				if(sizeof(dirs)==0) {
					str += "    这里没有任何明显的出路。\n";
				} else if(sizeof(dirs)==1) {
					str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
				} else {
					str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR
							+ " 和 " + BOLD + "%s" + NOR + "。\n",
							implode(dirs[0..sizeof(dirs)-2], "、"),
							dirs[sizeof(dirs)-1]);
				}
			} else {
				str += "    这里没有任何明显的出路。\n";
			}
			inv = all_inventory(environment());
			for(i=0; i<sizeof(inv); i++) {
				if(inv[i]==this_object()) continue;
				if(inv[i]->query("no_shown")) continue;
				if(!this_object()->visible(inv[i]) ) continue;
				str += "  " + inv[i]->short() + "\n";
			}
			tell_object(this_object(), str);
		} else {
			command("look");
		}
	}
	return result;
}

void receive_message(string cl, string msg) {
	if(this_object()->query_temp("char_encoding") == "big5") {
		msg = ENCODE_D->gbTobig5(msg);
	}
	::receive_message(cl, msg);
}

string process_input(string str) {
	if(this_object()->query_temp("char_encoding") == "big5") {
		str = ENCODE_D->big5Togb(str);
	}
	return ::process_input(str);
}

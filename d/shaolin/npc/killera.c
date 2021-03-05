// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit SMART_NPC;
#include <ansi.h>
void create()
{
        set_name("蒙面客首领", ({ "figure leader"}) );
        set("nickname", HIG "拳不留命"NOR);
        set("gender", "男性" );
        set("age", 41);
		set("per", 30);
        set("agi",25);
        set("class","beggar");
		set("attitude","friendly");
		set("bellicosity",30000);
	    set("figure_friend",1);
        
        set("long",
"这人的脸上戴着黑布面具，看不清面目，两颊深陷，两只手掌大的惊人。从
其他人对他的恭敬来看，显然是这一伙人的首领。\n"
	);
        set("combat_exp", 5000000);
        
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		
        auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","dragonstrike",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
		
}

void init()
{
        object ob;

        ::init();
        add_action("do_get","get");
        if( interactive(ob = this_player())) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{   
//	object friend;
	if( !interactive(ob) || environment(ob) != environment() ){
		return;
	}
	if (!ob->query("figure_friend"))
	{
			ccommand("say 竟然来坏我好事．．．");
			ccommand("heng");
			ccommand("say 天堂有路你不走，地狱无门投进来！");
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
	}
      	return;
}


int do_get(string arg)
{
	if(!arg) return 0;
	message_vision("$N笑道：没有这么便宜的事吧？\n",this_object(),this_player());
	this_player()->perform_busy(1);
	return 1;
}

void die()
{
//      int i;
        object killer, owner;
		object me;
        if(objectp(killer = query_temp("last_damage_from")))
		{
				if(owner=killer->query("possessed"))
					killer = owner;

				me = killer;
				if (REWARD_D->riddle_check(me,"多事之秋") == 6)
				{
					REWARD_D->riddle_set(me,"多事之秋",7);
					message_vision("蒙面客首领死了。\n",this_object());
					tell_object(me,CYN"\n你回想起来，此事大有可疑之处：\n");
					tell_object(me,"少林重地本是龙潭虎穴，却混入了如此之多身份不明之人；\n");
					tell_object(me,"一铁首座毙命于蒙面人手下，而经楼底的老僧竟毫无所觉；\n");
					tell_object(me,"而蒙面人所佩带的长刀又着实诡异。\n");
					tell_object(me,"所有的迹象仿佛都是个不祥的预兆．．．快回去向天峰大师"YEL"回报"CYN"吧。\n"NOR);
					move(load_object("/obj/void"));
				}

		}
        ::die();

}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/


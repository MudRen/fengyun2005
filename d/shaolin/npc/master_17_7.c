
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void getting();
int kill_him();
void create()
{
        set_name("心鉴", ({ "master jian", "master"}) );
        set("gender", "男性" );
        set("class", "shaolin");
        set("age", 44);
		set("per", 35);
		set("attitude","friendly");
        
        set("long","\n");
        create_family("少林寺", 17, "长老");
        
        set("combat_exp", 1200000);
        
        set_skill("move", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("unarmed",160);
		set_skill("puti-steps",150);
		set_skill("dabei-strike",150);
		set_skill("xiaochengforce",100);
		set_skill("parry",150);
	
		map_skill("parry","dabei-strike");
        map_skill("dodge", "puti-steps");
		map_skill("force", "xiaochengforce");
		map_skill("unarmed", "dabei-strike");
	
    	set("chat_chance", 15);
    	set("chat_msg", ({
			"神秘的人物左翻翻右翻翻．．．根本不把你放在眼里！\n",
			"神秘的人物用手敲了敲经书盒．．\n",
        	(: getting :)
    	}) );
        
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
            (: getting :),
            (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/skinmask")->wear();
	carry_object("/obj/armor/cloth")->wear();
}


void hide()
{
	object *inv;
	int i;
        if( !environment() ) return;
	inv = all_inventory(environment());
	for(i=0;i<sizeof(inv);i++)
		if (REWARD_D->riddle_check(inv[i],"守经楼") == 1)
			REWARD_D->riddle_set(inv[i],"守经楼",999);		// failed
	message_vision("$N阴笑一声：＂丢了经书，等着被心湖打屁股吧！＂\n",this_object());
	message_vision("$N一越，跳出窗口不见了．．．\n",this_object());
   	destruct(this_object());
}


void getting()
{
	command("get jingshuhe");
	call_out("hide",10+random(20));
}

void unconcious()
{
	die();
}

void die()
{
        int i;
        object killer, owner;
		object me;
        if(objectp(killer = query_temp("last_damage_from")))
		{
				if(owner=killer->query("possessed"))
					killer = owner;

				me = killer;
				if (REWARD_D->riddle_check(me,"多事之秋") == 3 && REWARD_D->riddle_check(me,"守经楼") == 1)
					REWARD_D->riddle_set(me,"守经楼",2);

				message_vision("$N见势不妙，飞身而起，自"YEL"窗口"NOR"疾越而出，消失不见。\n",this_object());
				move(load_object("/obj/void"));

				me=find_object("/d/shaolin/changjing5");
				if (!me)
					me=load_object("/d/shaolin/changjing5");
				me->init();

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



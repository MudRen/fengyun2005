// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit SMART_NPC;
#include <ansi.h>
void create()
{
        set_name("中年和尚", ({ "shaolin monk", "monk"}) );
        create_family("少林寺", 20, "弟子");
        set("gender", "男性" );
        set("class", "shaolin");
        set("age",random(20)+ 32);
		set("nickname",HIY"棍僧"NOR);
        set("long", "这是少林寺的棍僧。\n");
		set("vendetta_mark","shaolin");
        set("combat_exp", 4000000);
        
        set("attitude", "friendly");
		      
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"头一偏，整个人差点睡倒在地上。\n",
                name()+"神色端庄，口中振振有辞。\n",
                name()+"双眼微闭，嘴唇微动。。。\n",
		name()+"全身就像一块石头一样，一动不动。\n"
        }) );
        
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
     	}) ); 		

	auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","fumostaff",1);    
	setup();
	carry_object(__DIR__"obj/monk20_cloth")->wear();
	carry_object(__DIR__"obj/stick")->wield();
}


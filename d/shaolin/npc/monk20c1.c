// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("老僧", ({ "shaolin monk", "monk"}) );
        create_family("少林寺", 17, "弟子");
        set("gender", "男性" );
        set("age",random(30)+ 62);
		set("nickname",HIR"护寺僧"NOR);
        set("long", "这是少林寺护寺的老僧。\n");
		set("vendetta_mark","shaolin");
        set("combat_exp",5200000);
        set("attitude", "friendly");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"垂目道：心鉴师弟在此面壁，闲人不得入内。\n"
        }) );
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(40) :),
     	}) ); 		

		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","yiyangzhi2",1);
		setup();
		carry_object(__DIR__"obj/monk20c_cloth")->wear();
}

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
		set("nickname",HIR"兼通数艺"NOR);
        set("long", "这是少林寺专门研究各派武功，寻找破解各派绝招的和尚。\n");
		set("vendetta_mark","shaolin");
        set("combat_exp",5000000);
        set("attitude", "friendly");
        set("cor",20);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"叹道：又是秋天了吗？\n",
                name()+"笑道：你想看这里的秘笈？\n",
                name()+"道：给你看也没有用，你的天赋不够！\n",
				name()+"道：老衲已经二十余载没有下楼一步了！\n"
        }) );
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(15) :),
     	}) ); 		

		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","yiyangzhi2",1);
		setup();
		carry_object(__DIR__"obj/monk20c_cloth")->wear();
}

// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("壮年和尚", ({ "shaolin monk", "monk"}) );
        create_family("少林寺", 18, "弟子");
        set("gender", "男性" );
        set("class", "shaolin");
        set("age",random(20)+ 32);
		set("nickname",HIG"专攻一项"NOR);
        set("long", "这是少林寺专门研究各派武功，寻找破解各派绝招的和尚．\n");
		set("vendetta_mark","shaolin");
        
        set("combat_exp", 4500000);
        set("attitude", "friendly");
                       
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"叹道：难哪！这［天地人魔连环八式］真是毫无破绽！\n",
                name()+"笑道：也不知这李玉函，柳无眉夫妇如何在江湖
立足！这黄山派武功一招中有不下十个破绽！\n",
                name()+"道：这七仙女阵也不过如此！\n",
				name()+"叫道：终于被我找出破绽了！\n"
        }) );
	
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(10) :),
     }) ); 		

	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","fumostaff",1);
	setup();
	carry_object(__DIR__"obj/monk20b_cloth")->wear();
	carry_object(__DIR__"obj/stick")->wield();
}

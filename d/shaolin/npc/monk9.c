// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	string *name = ({"弈","林","粹","签","华","阳","峙"});
        set_name("空"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("age",random(20)+ 32);
	create_family("少林寺", 23, "弟子");
        set("long", "这是少林寺的和尚\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(1000)+100000);
        set("attitude", "friendly");
        set_skill("unarmed", 60+random(10));
	set_skill("dabei-strike",random(10)+70);
	set_skill("move",40);
	set_skill("force",20);
	
	map_skill("unarmed", "dabei-strike");
        set("chat_chance", 20);
        set("chat_msg", ({
                name()+"拿起一块布擦了擦桌子．\n",
		name()+"看了你一眼：你来晚了，开饭时间刚过．\n",
		name()+"低头一边扫地一边道：来早也没有，还没到时间呢！\n"
        }) );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );

	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}


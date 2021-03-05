// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("守护僧", ({ "shaolin monk", "monk", "guard monk"}) );
	create_family("少林寺", 20, "弟子");
	set("gender", "男性" );
	set("age",random(20)+ 32);
	set("nickname","棍僧");
	set("long", "这是少林寺的棍僧。\n");
	set("vendetta_mark","shaolin");
	set("combat_exp", random(300000)+10000);
	set("attitude", "friendly");

	set_skill("staff", 5+random(200));
	set_skill("xingyi-stick",random(150)+20);
	set_skill("move",400);
	set_skill("force",200);
	map_skill("staff", "xingyi-stick");

	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/stick")->wield();
}


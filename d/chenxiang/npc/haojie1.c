// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("武林大豪杰", ({ "toughman" }) );
	set("gender", "男性" );
	set("age", 47);
	set("long", "这个人一看就象是武林中人。\n");
	set("combat_exp", 100000);
	set("chat_chance", 1);
	set("chat_msg", ({
		"武林大豪杰高声骂道：老子的刀都砍钝了，鸟也没发现一个！\n",
	}) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/miaodao")->wield();
}

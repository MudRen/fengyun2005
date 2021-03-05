// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("红嘴小麻雀", ({ "maque", "que" }) );
	set("race", "飞禽");
	set("gender", "雄性");
	set("age", 3);
	set("long", "这是一只红嘴小麻雀。\n");
	set("attitude", "peaceful");
	set("combat_exp",5000);
        set("chat_chance", 1);
        set("chat_msg", ({
		"小麻雀＂叽～～叽叽＂地鸣叫了几声\n",
        }) );
	set_temp("apply/attack", 60);
	set_temp("apply/dodge",40);
	setup();
}

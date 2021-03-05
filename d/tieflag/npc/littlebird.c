// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("小山雀", ({ "bird", "little bird" }) );
	set("race", "飞禽");
	set("gender", "雄性");
	set("age", 1);
	set("long", "这是一只好可爱的小山雀。\n");
	set("attitude", "peaceful");
	
        set("chat_chance", 1);
        set("chat_msg", ({
		"小山雀＂叽～～叽叽＂地向你要东西吃。\n",
        }) );
	set_temp("apply/attack", 400);
	set_temp("apply/armor", 40);
	set_temp("apply/dodge",400);
	set("combat_exp",1000000);
	setup();
	carry_object(AREA_TIEFLAG"npc/obj/tongue",(["name":"小山雀舌"]));
}

// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	set_name("沉香镇的地头蛇", ({ "gangster" }) );
	set("gender", "男性" );
	set("age", 27);
	set("long", "这个人是专门在沉香镇不务正业，坐地分赃的。\n");
	set("combat_exp", 10000);
	
	set("chat_chance", 2);
	set("chat_msg", ({
		"沉香镇的地头蛇喝道：老子就是看你不顺眼，你怎么着？\n",
		(: random_move :)
	}) );
	
	set("leave_msg", "溜哒开了");
	
	setup();
	
	carry_object("/obj/armor/cloth")->wear();

}

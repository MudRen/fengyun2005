// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("卖鱼的", ({ "fishseller" }) );
	set("gender", "男性" );
	set("age", 35);
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",1);
	set("vendor_goods", ([
		__DIR__"obj/freshfish" : 10,
		__DIR__"obj/shrimp" : 50,
	]) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "卖鱼的高声吆喝道：十文一斤喽．．活蹦乱跳的鲜鱼．．．\n",
                "卖鱼的说道：八文一斤．．？．．．\n",
                "卖鱼的说道：八文一斤．．？．．．\n",
                "卖鱼的低头沉思．．．\n",
        }) );

	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	add_action("do_vendor_list", "list");
}

void reset()
{
	set("vendor_goods", ([
		__DIR__"obj/freshfish" : 10,
		__DIR__"obj/shrimp" : 50,
	]) );
}

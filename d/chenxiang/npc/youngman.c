// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("卖面的年青人", ({ "youngman" }) );
	set("gender", "男性" );
	set("age", 25);
	set("long",
"这年青人一看就是当年老人的亲属，尤其是他的鼻子，特别象当年的老人。
\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",1);
	set("vendor_goods", ([
		__DIR__"obj/hezi" : 100,
        __DIR__"obj/jianskin" : 30,
		__DIR__"obj/caomian" : 100,
        __DIR__"obj/jiannan" : 30,
		__DIR__"obj/miantiao": 40,
		"/obj/food_item/wineskin" : 50,
	]) );
        set("inquiry", ([
                "杀人案" : "哦．．那已经是很久以前的事了．．听说那家伙有把刀，会喷火的刀，就是他杀的．\n",
		"murder" : "哦．．那已经是很久以前的事了．．听说那家伙有把刀，会喷火的刀，就是他杀的．\n",
        ]));

	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/qiju");
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0:
command("say 来试试看，刚出笼的！\n");	
			break;
	}
}

int accept_object(object me, object obj)
{
	command("say 多谢这位" + RANK_D->query_respect(me) + "\n");	
        return 1;
}


void reset(){
	set("vendor_goods", ([
		__DIR__"obj/hezi" : 100,
        __DIR__"obj/jianskin" : 30,
		__DIR__"obj/caomian" : 100,
        __DIR__"obj/jiannan" : 30,
		__DIR__"obj/miantiao": 40,
		"/obj/food_item/wineskin" : 50,
	]) );
}	
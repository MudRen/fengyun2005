// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int rape();

void create()
{
        set_name("丧尽天良的畜生", ({ "pig" }) );
        set("gender", "男性");
        set("age", 24);
	set("str",30);
        set("long",
                "这个人正在光天化日下强奸民女！！！\n");
        set("combat_exp", 6000);
        set("score", 400);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: rape() :),
        }) );
        set_skill("unarmed", 100);
        set_skill("parry", 20);
        set_skill("dodge", 40);
        setup();
}

void init()
{
	add_action("do_look","look");
	::init();
}

int rape() {
	object lady,ob=this_object();
	string msg;
	
	if (!lady=present("lady",environment(ob))) {
		message_vision("丧尽天良的畜生眼珠骨碌碌地转着，不怀好意地打量着你。\n",ob);
		return 1;
	}
	switch (random(3)) {
		case 0: msg="丧尽天良的畜生狞笑着剥下了千金小姐的鞋子。。\n";break;
		case 1: msg="丧尽天良的畜生狞笑着剥下了千金小姐的袜子。。\n";break;
		case 2: msg= "丧尽天良的畜生狞笑着剥下了千金小姐的。。。。\n";
	}
	msg+= "千金小姐高声呼救：救命呀！光天化日下强奸民女啦！\n";
	message_vision(msg,ob);
	return 1;
}

int do_look(string arg){

	if (arg && arg[0..2] == "pig" ){
		if (!present(arg))	return 0;
		write("这个人正在光天化日下强奸民女！！！\n");
		write("他看起来约二十多岁。\n");
		write("武功看起来好象深不可测，出手似乎极重。\n");
		return 1;
	}
	return 0;
}



void die()
{
	object me;
	me=this_object()->query_temp("last_damage_from");
	if(objectp(me))
        me->set_temp("marks/lady",1);
	::die();
}

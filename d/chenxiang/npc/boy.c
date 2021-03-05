// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int give_him();
void create()
{
	set_name("穿开裆裤的小孩儿", ({ "boy","little boy" }) );
	set("gender", "男性" );
	set("age", 5);
	set("long", "这是一个小小男孩，长得齿白唇红很是可爱。\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("per",20);
	set("arrive_msg", "歪歪扭妞地爬了过来");
	set("leave_msg", "歪歪扭妞地爬开了");
    	set("chat_chance", 1);
    	set("chat_msg", ({
	                (: random_move :)
    	}) );
    	set("inquiry", ([
	    	"开裆裤" : (: give_him :),
		"kaidangku" : (: give_him :),
    	]));
	
	setup();
	carry_object(__DIR__"obj/kaidang")->wear();
}
int give_him()
{
	object me /*, obj*/;
	me = this_player();
	if( !query("given")) {
		command("remove kaidangku");
		set_name("光屁股的小孩儿", ({"boy", "little boy"}) );
		command("give kaidangku to " + me->get_id());  
	
		set("given",1);
		return 1;
	} else {
		message_vision("$N低头看了看自己光着的屁股，对$n摇了摇头。\n", this_object(), me);
	}
	return 1;
}

void reset(){
	object *inv;
//	int i;
	set("given",0);
	inv = all_inventory(this_object());
	if(sizeof(inv) == 0){
		carry_object(__DIR__"obj/kaidang")->wear();
	}
}
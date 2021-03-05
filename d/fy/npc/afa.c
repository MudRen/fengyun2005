// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("阿发", ({ "a fa","fa" }) );
    	set("title", "小鲁班");
	set("gender", "男性" );
	set("age", 35);
	set("long",
		"这里很暗，你看不清阿发的样子。\n");
	set("combat_exp", 3000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		AREA_RESORT"obj/bblade" : 20,
        	AREA_RESORT"obj/bsword" : 20,
	]) );
	set_skill("unarmed",5);
	setup();
	carry_object("/obj/armor/cloth")->wear();
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
message_vision("$N对$n说：你地知唔知天下最犀利，功夫真是莫得顶，作木器最劲的还宾个？\n",this_object(),ob);
			break;
	}
}

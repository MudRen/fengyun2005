// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("小担贩", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("cor",12);
	set("long",
		"一个挑着小担子的年青小贩\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		"/obj/food_item/wineskin" : 10,
		"/obj/food_item/dumpling" : 30,
		"/obj/food_item/chicken_leg" : 40,
	]) );
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
	switch( random(3) ) {
		case 0:
            say( "小担贩笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，上山哪？\n");
			break;
		case 1:
            say( "小担贩用手抹了抹头上的汗，说道：这位" + RANK_D->query_respect(ob)
				+ "，山上的东西很贵的呦！\n");
			break;
		case 2:
            say( "小担贩说道：这位" + RANK_D->query_respect(ob)
				+ "，买不买？又便宜又好！\n");
			break;
	}
}

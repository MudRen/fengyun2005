// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
    	set_name("阿菜哥", ({ "waiter" }) );
	set("gender", "男性" );
    	set("title", "跑堂的" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
    	set("combat_exp", 3500);
	set("attitude", "friendly");
	set("vendor_goods", ([
        	"/obj/food_item/shuihu" : 10,
        	"/obj/food_item/shaobing" : 30,
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
            say( "阿菜哥笑呵呵地说道：这位" + RANK_D->query_respect(ob)
                + "，进来喝口水，歇歇脚吧。\n");
			break;
		case 1:
            say( "阿菜哥用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
		case 2:
            say( "阿菜哥说道：这位" + RANK_D->query_respect(ob)
                + "，小店的烧饼又香又脆，可是沉香一绝啊！\n");
			break;
	}
}

inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("小贩", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位小贩正卖力地卖着东西。\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		__DIR__"obj/skin" : 100,
		__DIR__"obj/peach" : 300,
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
			say( "小贩擦了擦汗说道：这位" + RANK_D->query_respect(ob)
				+ "，来，买这个。\n");
			break;
		case 1:
			say( "小贩在衣襟儿上抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，快来买呀。\n");
			break;
		case 2:
			say( "小贩说道：这位" + RANK_D->query_respect(ob)
				+ "，再不买可就没有了。\n");
			break;
	}
}


void reset(){
	set("vendor_goods", ([
		__DIR__"obj/skin" : 100,
		__DIR__"obj/peach" : 300,
	]) );
}	
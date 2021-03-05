// TIE@FY3
inherit NPC;
inherit F_VENDOR;
void create()
{
    	set_name("孙驼子", ({ "sun tuozi","sun" }) );
	set("gender", "男性" );
	set("age", 52);
	set("long","一个背驮得如同虾米一样的老汉。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
	set("vendor_goods", ([
		__DIR__"obj/tie1" : 10,
		__DIR__"obj/tie2" : 30,
		__DIR__"obj/tie3" : 10,
		__DIR__"obj/tie4" : 5,
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
            say( "孙驼子道：这位" + RANK_D->query_respect(ob)
				+ "，要买什么？\n");
			break;
		case 1:
            say( "孙驼子看着门外的落叶道：又到秋天了。。。。\n");
			break;
		case 2:
            say( "孙驼子向你问道：这位" + RANK_D->query_respect(ob)
                + "，您说说上官和小李谁胜算大些?？\n");

			break;
	}
}

// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("驼背老人", ({ "oldman", "man" }) );
	set("gender", "男性" );
	set("age", 52);
	set("long",
		"这位驼背老人望著炉火呆呆的出神。\n");
	set("combat_exp", 5000);
	set("vendor_goods", ([
		__DIR__"obj/liandao.c":99,
		__DIR__"obj/axe.c":99,
		__DIR__"obj/dingpa.c":99,
		__DIR__"obj/basket.c":99,
		__DIR__"obj/hammer.c":99,
		__DIR__"obj/chutou.c":99,
	]) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	add_action("do_vendor_list", "list");
}

void reset(){
		set("vendor_goods", ([
		__DIR__"obj/liandao.c":99,
		__DIR__"obj/axe.c":99,
		__DIR__"obj/dingpa.c":99,
		__DIR__"obj/basket.c":99,
		__DIR__"obj/hammer.c":99,
		__DIR__"obj/chutou.c":99,
	]) );
}
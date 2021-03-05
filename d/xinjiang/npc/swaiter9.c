// copyright apstone, inc 1998
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("卖馕的", ({ "nang seller" }) );
        set("gender", "男性" );
        set("age", 30);
        set("long",
                "一个普普通通的本地人，没有一点起眼的地方。\n");
	set("combat_exp", 2000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/nang": 120,
        ]) );
        setup();
        carry_object(__DIR__"obj/kacloth")->wear();
}

void init()
{
//      object ob;
        ::init();
        add_action("do_vendor_list", "list");
}

void reset(){
        set("vendor_goods", ([
                __DIR__"obj/nang": 120,
        ]) );
}	
	
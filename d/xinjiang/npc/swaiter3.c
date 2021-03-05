// copyright apstone, inc 1998
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("卖抓饭的", ({ "fan seller" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "这人身材高大，看起来似乎很有力气。\n");
	set("combat_exp", 2000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/rice": 120,
        ]) );
        setup();
        carry_object(__DIR__"obj/carpet")->wear();
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
                        say( "卖抓饭的高叫道：就这几份抓饭了，再不买就没有喽！\n");
}

void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/rice": 120,
        ]) );
}

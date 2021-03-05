// copyright apstone, inc 1998
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("卖地毯的", ({ "rug seller" }) );
        set("gender", "男性" );
        set("age", 30);
        set("long",
                "一个普普通通的本地人，没有一点起眼的地方。\n");
	set("combat_exp", 2000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/carpet": 120,
        ]) );
        setup();
        carry_object(__DIR__"obj/kacloth")->wear();
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
        say( "卖地毯的的高叫道：上好的新疆羊毛毯子呀！！\n");
}

void reset(){
        set("vendor_goods", ([
                __DIR__"obj/carpet": 120,
        ]) );	
	
}
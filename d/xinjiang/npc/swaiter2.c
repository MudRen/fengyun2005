// copyright apstone, inc 1998
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("卖烤包子的", ({ "bao seller" }) );
        set("gender", "男性" );
        set("age", 30);
        set("long",
                "一个随身带着很多袋子的人，用来给客人装包子的，他的脸上冒着油光。\n");
	set("combat_exp", 2000);
        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/baozi": 120,
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
                        say( "卖烤包子的高叫道：牛肉羊肉包子，又新鲜又好吃！！\n");
}

void reset(){
        set("vendor_goods", ([
                __DIR__"obj/baozi": 120,
        ]) );
}
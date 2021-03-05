// copyright apstone, inc 1998
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("阿依古丽", ({ "waiter" }) );
        set("gender", "女性" );
        set("age", 17);
        set("long",
                "一个眉清目秀的维吾尔族小姑娘，专门在这里卖葡萄。\n");
	set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "小姑娘");
        set("vendor_goods", ([
                __DIR__"obj/putao": 120,
        ]) );
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
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
                        say( "阿依古丽拿起一串葡萄笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，来买一串吧！\n");
                        break;
                case 1:
                        say( "阿依古丽对着你晃晃手中的大葡萄说道：这位" + RANK_D->query_respect(ob)
                                + "，亚克西姆赛斯！\n");
                        break;
                case 2:
                        say( "阿依古丽说道：这位" + RANK_D->query_respect(ob)
                                + "，这是咱们这最有名的东西了！\n");
                        break;
        }
}


void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/putao": 120,
        ]) );
}

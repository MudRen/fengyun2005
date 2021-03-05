inherit NPC;
inherit F_VENDOR;
inherit INQUIRY_MSG;

void create()
{
        set_name("卖茶的老妇人", ({ "oldwoman" }) );
        set("gender", "女性" );
        set("age", 60);
        set("long",
                "老妇人扯着把竹扇坐在树荫下，面前放着个大茶壶和几个篾碗。\n");
	set("combat_exp", 5);
	set("inquiry", ([
 		
   	]));

        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/teapot": 30,
               __DIR__"obj/dumpling": 30,
               __DIR__"obj/fan": 30,
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
                        say( "老妇人笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，过来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "老妇人用毛巾抹了抹篾碗说道：这位" + RANK_D->query_respect(ob)
                                + "，请坐请坐。\n");
                        break;
                case 2:
                        say( "老妇人说道：这位" + RANK_D->query_respect(ob)
                                + "，过来尝尝才采的新茶叶。哇! 好香啊!...\n");
                        break;
        }
}

void reset(){
	        set("vendor_goods", ([
                __DIR__"obj/teapot": 30,
               __DIR__"obj/dumpling": 30,
               __DIR__"obj/fan": 30,
        ]) );
}
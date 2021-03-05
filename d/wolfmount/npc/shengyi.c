inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

void create()
{
        set_name("郝生意", ({ "hao shengyi","hao" }) );
        set("long",
                "一个很和气，很客气的客栈老板。\n"
                );
        set("title",  "客栈老板" );

        set("attitude", "peaceful");

        set("combat_exp", 500000);
                set("inquiry", ([
                "狼山" : "唉，不要去送死了，最近朱五太爷脾气有点儿怪，还是不要惹恼他老人家。\n",
                "太平客栈" : "不是我吹牛，狼山方圆百里，就我这店太平。\n",
        ]) );
        set("chat_chance", 1);
        set("chat_msg", ({
                }) );

        set_skill("unarmed", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set("vendor_goods", ([
				__DIR__"obj/wolfskin":10,
                __DIR__"obj/wolfmeat":15,
                __DIR__"obj/wolfpen":20,
                __DIR__"obj/wolftea":15,
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
                        say( "郝生意笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来坐坐吧。\n");
                        break;
                case 1:
                        say( "郝生意拱手说道：这位" + RANK_D->query_respect(ob)
                                + "，财源广进，生意兴隆啊。\n");
                        break;
                case 2:
                        say( "郝生意说道：这位" + RANK_D->query_respect(ob)
                                + "，来点狼山特产吧，天下只有我这儿才买得到！\n");
                        break;
        }
}

void reset ()
{
        set("vendor_goods", ([
				__DIR__"obj/wolfskin":10,
                __DIR__"obj/wolfmeat":15,
                __DIR__"obj/wolfpen":20,
                __DIR__"obj/wolftea":15,
	]) );

}
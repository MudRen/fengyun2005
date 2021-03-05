// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("卖菜的", ({ "cai fan","fan" }) );
        set("gender", "男性" );
        set("age", 40);
        set("long",
                "一个为生活而终日奔波的小商人．\n");
	set("combat_exp", 2000);
        set("attitude", "friendly");
        set("rank_info/respect", "老二哥");
        set("chat_chance", 3);
        set("chat_msg", ({
                "卖菜的笑道：那一着天外飞仙，七搏一赌叶孤城胜．．\n",
        }) );

        set("vendor_goods", ([
                __DIR__"obj/smallvege":11,
                __DIR__"obj/bigvege":22,
                __DIR__"obj/midvege":22,
                __DIR__"obj/tomato":10,
                __DIR__"obj/cucumber":10,

        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}



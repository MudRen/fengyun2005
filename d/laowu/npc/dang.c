// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("唐可卿", ({ "keqing" }) );
	set("gender", "女性" );
	set("age", 21);
	set("long",
		"这位唐可卿笑咪咪地望着你。\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                __DIR__"obj/egg":20,
		"/obj/food_item/wineskin":10,
	]) );

	set_skill("unarmed",100);
	set_skill("tenderzhi",100);
	set_skill("dodge",100);
	set_skill("stormdance",100);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	
	set("chat_chance_combat", 45);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qiankun" :),
        }) );
	
	setup();
	carry_object(__DIR__"obj/bigcloth")->wear();
}

void init()
{
        add_action("do_vendor_list", "list");
        ::init();
}

void reset()
{
	set("vendor_goods", ([
                __DIR__"obj/egg":20,
		"/obj/food_item/wineskin":10,
	]) );
}

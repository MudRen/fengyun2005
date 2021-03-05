// waiter.c

inherit SMART_NPC;
inherit F_VENDOR;

void create()
{
	object weapon;
    set_name("明霞山小贩", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位明霞山小贩背着个竹篓，正在一棵树下乘凉。\n");
	set("combat_exp", 4900000);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		__DIR__"obj/staff" : 5,
		__DIR__"obj/tea" : 50,
		__DIR__"obj/food" : 50,
	]) );
	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(25) :),
        }) );

	setup();
        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("登山拐", ({ "staff" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("百兜裙", ({ "skirt" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",190,170,0,"/obj/weapon/","fighter_w","cloudstaff",1);

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
			say( "明霞山小贩大喝道：这位" + RANK_D->query_respect(ob)
				+ "且歇歇！再过去那山头高得很，先过来歇歇腿，挑挑登山杖吧。\n");
			break;
		case 1:
			say( "明霞山小贩招呼道：这位" + RANK_D->query_respect(ob)
				+ "，过来买点崩硬崩硬的干粮吧，便宜得很，五文！\n");
			break;
		case 2:
			say( "明霞山小贩招呼道：这位" + RANK_D->query_respect(ob)
				+ "，过来喝点滚烫滚烫的热茶吧，便宜得很，五文！\n");
			break;
	}
}



void reset()
{
        set("vendor_goods", ([
		__DIR__"obj/staff" : 5,
		__DIR__"obj/tea" : 50,
		__DIR__"obj/food" : 50,
		]) );
}



// 凝輕·dancing_faery@hotmail.com


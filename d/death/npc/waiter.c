// waiter.c

inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("马老四", ({ "max" }) );
	set("gender", "男性" );
	set("age", 62);
	set("long",	"这位店家满脸黑气，印堂发黑，一身白衣服，就象刚刚出殡回来一样。\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_temp("apply/astral_vision",1);
	set("rank_info/respect", "老店家");
	set("vendor_goods", ([
        __DIR__"obj/pumpkin" : 80,
		__DIR__"obj/wineskin": 80,
	]) );
	setup();
	carry_object("/obj/armor/ghost_cloth")->wear();
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
			say( "马老四道：这位" + RANK_D->query_respect(ob)
				+ "，投胎．．，哦哦．．不，不，投宿吗？\n");
			break;
		case 1:
			say( "马老四道：" + RANK_D->query_respect(ob)
				+ "，请进请进,早投宿，早起来。\n");
			break;
		case 2:
			say( "马老四咳道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝几盅小店的还阳酒吧！\n");
			break;
	}
}

void reset(){
	set("vendor_goods", ([
        __DIR__"obj/pumpkin" : 80,
		__DIR__"obj/wineskin": 80,
	]) );	
	
}
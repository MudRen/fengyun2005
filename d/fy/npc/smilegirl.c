inherit SMART_NPC;

void create()
{
	set_name("楚楚", ({ "chu chu","chu" }) );
	set("gender", "女性" );
	set("age", 18);
	set("long",
		"一个天真无邪，未懂世事的小丫环\n");
	set("combat_exp", 900000);
	set("attitude", "friendly");
	set("per",30);
	
	auto_npc_setup("wang",100,120,0,"/obj/weapon/","fighter_u","stormdance",1);
	setup();
	carry_object(__DIR__"obj/green_cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
message_vision("$N看了$n一眼，然后捂住小嘴儿开始＂吃吃＂的笑。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N盯了$n身上一眼，然后害羞地转过身，开始＂吃吃＂的笑。\n",this_object(),ob);
			break;
		case 2:
			command("snicker");
	}
}

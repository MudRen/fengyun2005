inherit NPC;
#include <ansi.h>

void create()
{
        set_name( "程小小", ({ "kid", "small kid" }) );
		set("title", "无知小童");
		set("gender", "男性" );
		set("age", random(5)+4);
		set("int", 26);
		set("long",
		"一个四五岁的小孩子，正在地上玩玻璃弹子。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "程小小说：长大后我要赚很多钱，而后去找鹦鹉姐姐。\n"
        }) );
		set("inquiry", ([
        	"*" : 	"我除了玩什么都不知道，什么都不想知道。\n",
   		]));
		set("attitude", "peaceful");
		set("combat_exp", 20000);
        set_skill("unarmed", 50);
        set_skill("taiji", 50);
        map_skill("unarmed", "taiji");
		setup();
		carry_object("obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/ball");
}


/*
void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player())) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	object paper;
	int pass;
	if( !ob || environment(ob) != environment()) return;

	if (ob->query("marks/parrot/遇刺") && ob->query("marks/parrot/宋妈妈家的秘密")
		&& ob->query("marks/parrot/红石的秘密") && ob->query("marks/parrot/尸体的秘密")
		&& ob->query("marks/parrot/初见血奴")&& ob->query("marks/parrot/杀宋妈妈")
		&& ob->query("marks/parrot/杀老蛔虫"))
		pass=1;
	
	
	if( pass && !random(5) && !ob->query("marks/parrot/甘老头的锁") && !ob->query("marks/parrot/助三爷")) {
		message_vision(CYN"$N道：“方才甘老头拿来一包东西，叫我交给你。”\n"NOR,this_object(),ob);
		ob->set("marks/parrot/甘老头的锁",1);
		paper= new(__DIR__"obj/paper");
		if (paper) {
			paper->move(this_object());
			command("give paper to "+ob->get_id());
		}
		return;
	}
}

*/
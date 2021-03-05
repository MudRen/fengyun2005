// 2009 FengYun
// Edit by hippo 2009.11
// 孝道 关联

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("读千里", ({ "du qianli","du","qianli" }) );
	set("gender", "男性" );
	set("age", 91);
	set("title", CYN "才高八斗"NOR);
	set("long","这位老板不但才高八斗，而且还是当今皇太子的老师。\n");
	set("combat_exp", 150000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                BOOKS"literate_21" : 50,
                BOOKS"force_21" : 	50,
                BOOKS"magic_21" : 	50,
                BOOKS"move_21" :	50,
                BOOKS"spells_21": 	50,
                BOOKS"fore_21":		50,
                BOOKS"chant_21":	50,
                BOOKS"unarmed_21":	50,
                BOOKS"swimming_30": 50,

	]) );
	
	set_skill("unarmed",150);
	set_skill("dodge",150);
	set_skill("parry",150);
	setup();
	carry_object(__DIR__"obj/fycloth")->wear();
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
	switch( random(10) ) {
		case 0:
message_vision("$N摇头晃脑地低吟道：良时不再至，离别在须臾。屏营衢路侧．．。\n",this_object(),ob);
			break;
		case 1:
message_vision("$N望了$n一眼，低哼道：结发为夫妻，恩爱两不疑。欢娱在今夕．．。\n",this_object(),ob);
			break;
	}
}


void reset()
{
	if (random(5))
	{
		set("vendor_goods", ([
                BOOKS"literate_21" : 50,
                BOOKS"force_21" : 	50,
                BOOKS"magic_21" : 	50,
                BOOKS"move_21" :	50,
                BOOKS"spells_21": 	50,
                BOOKS"fore_21":		50,
                BOOKS"chant_21":	50,
                BOOKS"unarmed_21":	50,
                BOOKS"swimming_30": 50,
								//__DIR__"obj/mo": 0,
		]) );
	} else
	{
		set("vendor_goods", ([
                BOOKS"literate_21" : 50,
                BOOKS"force_21" : 	50,
                BOOKS"magic_21" : 	50,
                BOOKS"move_21" :	50,
                BOOKS"spells_21": 	50,
                BOOKS"fore_21":		50,
                BOOKS"chant_21":	50,
                BOOKS"unarmed_21":	50,
                BOOKS"swimming_30": 50,
								__DIR__"obj/mo": 1,
		]) );
	}
}
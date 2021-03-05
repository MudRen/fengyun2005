#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("老山东", ({ "old shandong","shandong" }) );
	set("gender", "男性" );
	set("title","馒头店老板");
	set("age", 46);
	set("long",
		"这人并不太老，但被烟把脸都熏黑了。只有笑起来的时候，才会露出\n一口雪白的牙齿。\n"
		"据说丁喜和小马这一班饿虎岗的大小强盗们都是他的常客。\n");
	set("combat_exp", 540000);
	set("attitude", "friendly");
	set("per",5);
	set("vendor_goods", ([
        	__DIR__"obj/mantou":120,
			__DIR__"obj/shaoji":120,
	]) );
	set("inquiry",	([
			"丁喜" : "老山东瞪着眼看了你半天，忽然笑了起来：“丁喜的朋友啊？！......\n馒头烧鸡全都有。在这慢慢吃，别噎着。”",
			"小马" : "老山东瞪着眼看了你半天，忽然笑了起来：“小马的朋友啊？！......\n馒头烧鸡全都有。在这慢慢吃，别噎着。”",
	]) );
	set_skill("unarmed",100);
	set_skill("dodge",100);
	
	setup();
	carry_object(__DIR__"obj/dirty_cloth")->wear();
	carry_object(__DIR__"obj/sd_skinmask");
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


void greeting(object ob){
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) 
	{
		case 0:
			message_vision("$N瞅了$n一眼，懒洋洋道：这位"+RANK_D->query_respect(ob)+"，小店打烊了。\n",this_object(),ob);

			break;
		case 1:
			message_vision("$N叹道：小马上狼山，丁喜进虎口，十有八成是有去无回啊。\n$N连连摇着头，嘴角却浮现出一丝诡秘的笑容：“可惜呀，可惜....\n多么好的两个小伙子呀......”\n",this_object());

			break;
	}
}

void reset ()
{
	set("vendor_goods", ([
        	__DIR__"obj/mantou":120,
			__DIR__"obj/shaoji":120,
	]) );
}

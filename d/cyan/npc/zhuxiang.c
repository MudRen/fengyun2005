// waiter.c
#include <ansi.h>
inherit SMART_NPC;
inherit F_VENDOR;

void create()
{
	object weapon;
    set_name("朱颜", ({ "zhu yan","zhuyan","yan" }) );
	set("gender", "女性" );
	set("age", 16);
	set("price_modifier",500);
	set("per",32);
	set("score",-32);
	set("title",WHT"山间秀色"NOR);
	set("long","一个清秀动人的长发少女，正扶着自己的脚靠在山壁之上。\n");
	set("combat_exp", 7200000);
	set("attitude", "friendly");
	
	set("chat_chance",2);
	set("chat_msg", ({
		"朱颜长长的睫毛下笼着一层水雾，泪光点点，看起来分外动人。\n",
		"朱颜楚楚可怜地咬着嘴唇，轻轻道：竹马……人家好想你……\n",
		"朱颜的脸上现出一丝痛苦之色，望着搁在身边的竹篮犹豫不决。\n",
	}) );

	set("vendor_goods", ([
		__DIR__"obj/amulet1" : 1,
		__DIR__"obj/amulet2" : 1,
		__DIR__"obj/amulet3" : 1,
		__DIR__"obj/amulet4" : 1,
		__DIR__"obj/amulet5" : 1,
		__DIR__"obj/amulet6" : 1,
	]) );
	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );

		set("death_msg",CYN"\n$N捂着心口，踉跄了两步，咬牙道：你……好狠心……\n"NOR);

		auto_npc_setup("waiter",150,200,0,"/obj/weapon/","fighter_w","daimonsword2",4);
		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name(CYN"青霜结"NOR, ({ "relic knot","blade" }) );
		weapon->set("long","一柄形状古怪的武器。\n");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name(MAG"粉紫纱裙"NOR, ({ "longskirt" }) );
		weapon->set("long","一条粉紫轻纱织就的长裙，裙内风光隐约可见。\n");
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/boots");
        weapon->set_name("渗出血迹的素鞋", ({ "shoes" }) );
		weapon->set("value",0);
		weapon->wear();


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
			say( "朱颜抬头看了你一眼，嘴唇蠕动了两下，又低下头去。\n");
			break;
		case 1:
			say( "朱颜倚在山壁上，呆呆地听着风鸣，一点也没有注意到你。\n");
			break;
	}
}

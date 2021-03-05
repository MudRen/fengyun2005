// waiter.c
#include <ansi.h>
inherit SMART_NPC;
inherit F_VENDOR;

void create()
{
	object weapon;
    set_name("穆晟", ({ "mu cheng","mu","cheng" }) );
		set("title",BLU"神教外务"NOR);
		set("nickname",MAG"司库右仆"NOR);
	set("gender", "男性" );
	set("age", 22);

	
	set("price_modifier",10000);
	set("combat_exp", 8000000);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		__DIR__"obj/tea1" : 3,
		__DIR__"obj/food1" : 3,
		__DIR__"obj/food2" : 3,
		__DIR__"obj/cicada" : 1,
		__DIR__"obj/cloth1" : 1,
		__DIR__"obj/cloth2" : 1,
	]) );

		set("chat_chance",1);
	set("chat_msg", ({
		"穆晟不理身边芦涤的哀泣，仰头看着蓝天，似乎天上随时都会掉下个金元宝。\n",
	}) );

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(45) :),
        }) );

	setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("百两千两万两袍", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",230,280,0,"/obj/weapon/","fighter_w","dragonstrike-jg",1);

}


void init()
{	
	object ob;
	::init();
	add_action("do_vendor_list", "list");
	add_action("do_buy", "buy");
}


int do_buy(string arg)
{
	if ("/cmds/std/buy"->main(this_player(),arg))
		add("price_modifier",1000);
	else
	{
		this_player()->delete_temp("timer/buy");
		return 0;
	}
	return 1;
}

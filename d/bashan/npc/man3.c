// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("华山门下", ({ "huashan dizi" }) );

		set("title","前来观礼的"NOR);

		set("gender", "女性" );
		set("age",37);


	set("chat_chance",1);
	set("chat_msg", ({
		"众人窃窃私语，提及顾道人当年风范，无不景仰。\n",
	}) );

        set("inquiry",([
 		"顾道人"  :"顾道人那真个是了不起，了不起啊了不起。\n",
 		"顾剪秋"  :"顾道人那真个是了不起，了不起啊了不起。\n",
 		"九月初九"  :"action华山门下脸上飞上一抹红晕：人家第一次的日子，不要拿来乱说……\n",
 		"第一次"  :"action华山门下羞红着脸道：你但去找个人试试，便知道什么是第一次了。\n",
              ]) );

        set("combat_exp", 3200000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );


		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("银色的绣花针", ({ "needle" }) );
		weapon->set("unit","根");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("梅花短衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",200,160,0,"/obj/weapon/","fighter_w","qingfeng-sword",2);
}

// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("少林和尚", ({ "shaolin dizi" }) );

		set("title","前来观礼的"NOR);

		set("gender", "男性" );
		set("age",37);


		set("chat_chance",1);
		set("chat_msg", ({
			"众人窃窃私语，提及顾道人当年风范，无不景仰。\n",
		}) );

        set("inquiry",([
 		"顾道人"  :"顾道人那真个是了不起，了不起啊了不起。\n",
 		"顾剪秋"  :"顾道人那真个是了不起，了不起啊了不起。\n",
 		"九月初九"  :"action少林和尚惊叫道：你怎么知道和尚在那天偷偷开荤？\n",
		"开荤" :"开荤么．．天机广场那里南，南，南，西，西，西南，南，西便是了。",
              ]) );


        set("combat_exp", 3700000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );

		setup();
        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("降妖杵", ({ "staff" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/weapon/hammer");
        weapon->set_name("赶月锤", ({ "hammer" }) );
		weapon->set("value",0);

        weapon=carry_object("/obj/weapon/spear");
        weapon->set_name("七寸短枪", ({ "spear" }) );
		weapon->set("value",0);

        weapon=carry_object("/obj/weapon/axe");
        weapon->set_name("杀生斧", ({ "axe" }) );
		weapon->set("value",0);

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("百衲衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",200,160,0,"/obj/weapon/","fighter_w","wuche-axe",2);

}

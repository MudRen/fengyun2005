// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
		object weapon;
        set_name("帝王谷门人", ({ "diwanggu dizi" }) );

		set("title","前来观礼的"NOR);

		set("gender", "男性" );
		set("age",37);

        set("inquiry",([
 		"顾道人"  :"顾道人那真个是了不起，了不起啊了不起。\n",
 		"顾剪秋"  :"顾道人那真个是了不起，了不起啊了不起。\n",
 		"九月初九"  :"action帝王谷门人沉思片刻道："YEL"家师"CYN"每到九月初九，定会"YEL"闭关"CYN"三天。\n",
 		"闭关"  :"闭关么，就是人不在，挂着个机器人打坐读书练习加内力。\n",
 		"家师"  :"家师就是帝王谷谷主萧王孙。\n",
 		"萧王孙"  :"帝王谷谷主萧王孙就是家师。\n",
              ]) );

		set("chat_chance",1);
		set("chat_msg", ({
			"众人窃窃私语，提及顾道人当年风范，无不景仰。\n",
		}) );

        set("combat_exp", 3700000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );

		setup();

        weapon=carry_object("/obj/weapon/hammer");
        weapon->set_name("苍蝇拍", ({ "pai" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("青龙战甲", ({ "armor" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",200,170,0,"/obj/weapon/","fighter_w","pangu-hammer",2);
}

// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
		object weapon;
        set_name("丐帮弟子", ({ "gaibang dizi" }) );

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
 		"九月初九"  :"action丐帮弟子支支吾吾：那天我被狗咬了，求求你不要告诉帮主……\n",
              ]) );

		set("combat_exp", 2700000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );


		setup();

        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("赶狗棍", ({ "staff" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("很多袋子的布衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",170,160,0,"/obj/weapon/","fighter_w","dagou-stick",2);
}

// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
		object weapon;
        set_name("武当小道", ({ "wudang dizi" }) );

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
 		"九月初九"  :"action武当小道长吟道：九月初九登高日，遍插茱萸少一人，少一人哪。\n",
 		"茱萸"  :"茱萸那可是一味良药。\n",
              ]) );

        set("combat_exp", 4200000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("真六剑", ({ "sword" }) );
		weapon->set("unit","根");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("纯白道袍", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",200,180,0,"/obj/weapon/","fighter_w","taiji-sword",2);
}

// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();

void smart_fight()
{

	if (!random(5))
		ccommand("perform fenqin");
	else
	{
		ccommand("enable blade spring-blade");
			ccommand("perform fengsiyunqi");
		ccommand("enable blade beilongblade");

	}
	ccommand("perform changrijiangjin");
}

void create()
{
	object weapon;
	set_name("姜无恨", ({ "jiang wuhen","jiang","wuhen","jiangwuhen" }) );
	set("class","official");
	set("gender", "男性" );
	set("age", 46);

	set("nickname",RED"天理无常"NOR);
	set("title","朝廷命官 "CYN"刑部执事"NOR);

	set("no_fly",1);
	set("no_arrest",1);

	set("attitude", "peaceful");

	set("inquiry",([
		"饮血平寇": "action姜无恨的眼睛渐青，透明锋锐得仿若一对无暇的翡翠。\n姜无恨嘴角露出一丝狞笑："WHT"推豆腐"CYN"推多了，近日老夫便要推推人头。",
		"推豆腐":  "用一把大刀反手提着，顺在乎背上。刀锋向外，以刀锋\n片豆腐，片得愈薄愈好，等到手法练熟了，就在豆腐上划出墨线，要\n一刀推下去，让豆腐齐线而断，不差分毫，再在豆腐上置铜钱，刀锋\n过处，豆腐片落，而铜钱不落，才算小成。",
		]) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"姜无恨道：要练姜家的刀法，必先推上三年的豆腐。不推豆腐，就练不成。\n",
		"姜无恨道：姜家运刀的要诀便是了解。对人身上每一个骨节的构造，每一根\n肌肉的跃动，以及每一个人在面临致命一刀时的各种反应了如指掌，杀人就\n如疱丁解牛一般游刃有余。\n",
	}) );

	set("combat_exp", 5700000);

	set_skill("blade", 200);
	set_skill("beilongblade", 220);
	set_skill("spring-blade", 220);
	map_skill("blade","beilongblade");

	set_skill("unarmed", 200);
	set_skill("luoriquan", 220);
	map_skill("unarmed","luoriquan");


	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight() :),
	}) );

	setup();

	
	carry_object("/d/shenshui/obj/medicine");

        weapon=carry_object("/obj/weapon/blade/pxblade");
        weapon->set_name(MAG"奇形长刀"NOR, ({ "blade" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("执事长袍", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


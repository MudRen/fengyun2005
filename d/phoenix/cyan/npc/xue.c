// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();

void smart_fight()
{
	if (random(2))
		ccommand("perform luoxiang");
	else
	{
		ccommand("enable sword lefthand-sword");
			ccommand("perform duxin");
		ccommand("enable sword windsword");

	}
	ccommand("perform changrijiangjin");
}

void create()
{
	object weapon;
	set_name("薛墨之", ({ "xue mozi","xue","mozi","xuemozi" }) );
	set("class","moon");
	set("gender", "男性" );
	set("age", 46);

	set("nickname",MAG"无双神剑"NOR);
	set("title","中原薛家 "CYN"督戒"NOR);

	set("no_fly",1);
	set("no_arrest",1);

	set("attitude", "peaceful");

	set("inquiry",([
		"饮血平寇": "action薛墨之双指一按，一柄亮若秋水的长剑自剑鞘跃然而出。\n他盯著慢慢滑落回鞘的剑身半晌，轻轻地叹了口气。",
		]) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"薛墨之叹道：青碧天资聪颖，年方九岁便已得七分真传，惟骄气着实太重，只怕不是好事。\n",
		"薛墨之摇摇头：木秀于林，风必摧之，堆出于岸，流必湍之，行高于人，众必非之．．．\n",
	}) );

	set("combat_exp", 4800000);

	set("always_duxin",1);

	set_skill("sword", 200);
	set_skill("lefthand-sword", 220);
	set_skill("windsword", 220);
	map_skill("sword","windsword");

	set_skill("unarmed", 200);
	set_skill("luoriquan", 220);
	map_skill("unarmed","luoriquan");


	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight() :),
	}) );

	setup();

	
	carry_object("/obj/medicine/pill_zhuguo");

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(WHT"洞烛"NOR, ({ "sword" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("紫长衫", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


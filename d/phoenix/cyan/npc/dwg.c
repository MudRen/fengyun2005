// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();

void smart_fight()
{
	ccommand("perform tianleiyiji");
	ccommand("perform changrijiangjin");
}

void create()
{
	object weapon;
	set_name("萧长生", ({ "xiao changsheng","xiao","changsheng","xiaochangsheng" }) );
	set("class","yinshi");
	set("gender", "男性" );
	set("age", 46);

	set("nickname",CYN"七界心火"NOR);
	set("title","帝王谷 "CYN"隐士"NOR);

	set("no_fly",1);
	set("no_arrest",1);

	set("attitude", "peaceful");

	set("inquiry",([
		"饮血平寇": "西南裴冥通天适临谷中，谷主不克分身，夫人又近"WHT"临产"CYN"，是以只能遣我前来。",
		"临产": "夫人说了，若生女就起名萧缘，若生男便唤作王孙。",
		]) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"萧长生道：天庭近日缘花少，忽忆人间遇王孙．．好诗，好诗。\n",
		"萧长生道：夫人说了，若生女就起名萧缘，若生男便唤作王孙。\n",
	}) );

	set("combat_exp", 5000000);

	set_skill("whip", 200);
	set_skill("thunderwhip", 220);
	map_skill("whip","thunderwhip");

	set_skill("unarmed", 200);
	set_skill("luoriquan", 220);
	map_skill("unarmed","luoriquan");

	set_skill("hammer", 200);
	set_skill("pangu-hammer", 220);
	map_skill("hammer","pangu-hammer");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight() :),
	}) );

	setup();

	
	carry_object("/d/phoenix/npc/obj/cyan_drug2");

        weapon=carry_object("/obj/weapon/whip");
        weapon->set_name(RED"赤衣带"NOR, ({ "whip" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("青长衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


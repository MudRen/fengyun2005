#include <ansi.h>
inherit SMART_NPC;
void nb_smart_fight();

void create()
{
	set_name("土土", ({ "dark bringer","bringer" }) );
	set("title",YEL"西方神教"NOR);
	set("nickname","闇域使者");
	set("gender", "男性");
	set("combat_exp", 10000000);
	set("attitude", "peaceful");
	set("class","official");
	set("reward_npc",1);
	set("difficulty",1);
	set("no_fly",1);
	set("no_arrest",1);
	set("age",64);

	set("nb_chat_chance", 100);
	set("nb_chat_msg_combat", ([
		100: 	(: nb_smart_fight() :),
	]) );    	

	set_skill("unarmed", 100);
	set_skill("whip", 400);
	set_skill("force", 180);
	set_skill("parry", 120);
	set_skill("literate", 140);
	set_skill("dodge", 140);
	set_skill("move",160);
	set_skill("cursism",300);
	set_skill("celecurse",200);
	set_skill("flying-dragon", 150);
	set_skill("thunderwhip", 180);
	set_skill("manjianghong", 800);
	set_skill("zuixian-steps", 160);
	set_skill("perception", 100);

	set("marks/hammerwhip",1);

	set_skill("pangu-hammer", 150);
	set_skill("pofeng-strike", 150);
	
	set_skill("spear", 800);
	set_skill("yue-spear", 600);

	map_skill("unarmed", "pofeng-strike");
	map_skill("hammer", "pangu-hammer");
	map_skill("cursism","celecurse");
	map_skill("unarmed", "flying-dragon");
	map_skill("whip", "thunderwhip");
	map_skill("force", "manjianghong");
	map_skill("parry", "thunderwhip");
	map_skill("dodge", "zuixian-steps");

	map_skill("spear", "yue-spear");

	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/spear")->wield();
	carry_object("/obj/money/coin");
}


nb_smart_fight()
{
	object target=select_opponent();
	if (is_busy())
		return;
	ccommand("perform zonghengtianxia");
	return;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

// 5个此NPC(10M，400 whip，Full master xiao)就可以接近毫发无伤的杀死chi you...
// (通常最多受到2-5 hit)

#include <ansi.h>
inherit SMART_NPC;
void nb_smart_fight();

void create()
{
	set_name("虹", ({ "neon","foxgirl" }) );
	set("gender", "女性");
	set("combat_exp", 10000000);
	set("attitude", "peaceful");
	set("class","yinshi");
	set("no_fly",1);
	set("no_arrest",1);

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
	set_skill("iceheart", 150);
	set_skill("zuixian-steps", 160);
	set_skill("perception", 100);

	set("marks/hammerwhip",1);

	set_skill("pangu-hammer", 150);
	set_skill("pofeng-strike", 150);

	map_skill("unarmed", "pofeng-strike");
	map_skill("hammer", "pangu-hammer");
	map_skill("cursism","celecurse");
	map_skill("unarmed", "flying-dragon");
	map_skill("whip", "thunderwhip");
	map_skill("force", "iceheart");
	map_skill("parry", "thunderwhip");
	map_skill("dodge", "zuixian-steps");

	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/whip");
	carry_object("/obj/money/coin");
}


nb_smart_fight()
{
	object target=select_opponent();
	if (is_busy())
		return;
	if (target->is_busy())
	{
		ccommand("drop 1 coin");
		ccommand("get 1 coin");
		// 绝不作普通攻击，以防反击 *giggle
		return;
	}
	else
		ccommand("perform yunlongjiuxian");
	return;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

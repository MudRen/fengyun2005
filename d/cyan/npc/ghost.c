
#include <ansi.h>
inherit SMART_NPC;
void smart_fight(int t);

void create()
{
	object weapon;
	set_name("赵大先生", ({ "zhao da","zhao","zhaoda" }) );
	set("title","阎罗伞");
	set("gender", "男性" );
	set("long","赵大先生原为五殿阎罗之首，一柄油纸伞下夺去无数江湖好汉性命。\n");

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("busy_immune",4);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight(20) :),
	}) );

	set("combat_exp", 8000000);

	set("chat_chance",1);
	set("chat_msg", ({
		CYN"迷失的怨魂坐在地上，哈哈笑道：看见没？看见没？这是皇上的玉玺啊！\n"NOR,
	}) );

	setup();

	set_skill("spear",300);
	set_skill("eclipse-spear",220);
	map_skill("spear","eclipse-spear");

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("锦绣黄袍", ({ "cloth" }) );
	weapon->set("long","一件破破烂烂的黄袍。\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/spear");
	weapon->set_name("重机长枪", ({ "spear" }) );
	weapon->set("long","这是柄当年南疆第一铸铁师重机先生精心打造的长枪。\n");
	weapon->set("value",0);
	weapon->wield();
}




int kill_ob(object who)
{
	::kill_ob(who);
	smart_fight(100);	// rascal design :p
	return 1;
}

void smart_fight(int t)
{
	if (t <= random(100))
		return;

	ccommand("perform riyuetongtian");
	return;
}

int is_ghost()
{
	return 1;
}

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

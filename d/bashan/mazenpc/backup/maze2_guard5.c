#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("紧那罗部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "女性" );

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

		set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(100) :),
	}) );

	set("combat_exp", 6000000);

	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	setup();
	add_money("coin" , 1+random(100));

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","illusionstick2",4);

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("罗汉袈裟", ({ "monk cloth","cloth" }) );
	weapon->set("long","一件绘有九天魔像的奇异袈裟。\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/staff");
	weapon->set_name(HIG"绿叶青竹棒"NOR, ({ "bamboo stick","stick" }) );
	weapon->set("long","一根绿叶青竹棒。\n");
	weapon->set("value",0);
	weapon->wield();

}

int kill_ob(object who)
{
	::kill_ob(who);
	auto_smart_fight(100);	// rascal design :p
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

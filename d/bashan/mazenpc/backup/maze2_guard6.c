#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("迦楼罗部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "女性" );
		set("attitude", "aggressive");
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);


	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(100) :),
	}) );

	set("combat_exp", 6000000);

	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	setup();
	add_money("coin" , 1+random(100));

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","demonblade2",4);

	set_skill("music",250);

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("武卫铠", ({ "the guardian","guardian" }) );
	weapon->set("long","精钢炼化的铁甲。\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/music/qixianqin");
	weapon->set_name(RED"心焚琴"NOR, ({"tremor ting","ting" }) );
	weapon->set("long","一个暗红色的木琴。\n");
	weapon->set("value",0);
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

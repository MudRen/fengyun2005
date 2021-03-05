#include <ansi.h>
inherit SMART_NPC;
void smart_fightx();

void create()
{
	object weapon;
	set_name("迦楼罗部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "男性" );
	set("nickname",HIR"天魔 地魔 人魔 心魔"NOR);
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(30) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	auto_npc_setup("disciple",200,220,0,"/obj/weapon/","fighter_w","demon-blade",2);
	setup();

	weapon=carry_object("/obj/weapon/blade");
	weapon->set_name(NOR CYN"风神斩"NOR, ({"whole gale","gale" }) );
	weapon->set("long","这是一柄锋锐的长刀，刀柄上雕着小小的＂江门铸造＂四字。\n");
	weapon->set("value",0);
	weapon->wield();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("武卫铠", ({ "the guardian","guardian" }) );
	weapon->set("long","精钢炼化的铁甲。\n");
	weapon->set("value",0);
	weapon->wear();

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

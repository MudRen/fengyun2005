#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("摩呼罗迦部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("title",HIR"千招万招 不如一招"NOR);
	set("gender", "男性");
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(30) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","feixian-sword",1);
	setup();

	weapon=carry_object("/obj/weapon/sword");
	weapon->set_name(NOR MAG"天外神罗"NOR, ({"shinra" }) );
	weapon->set("long","这是一柄精巧的短剑，剑柄上雕着一面大旗，旗边刻了个小小的＂江＂字。\n");
	weapon->set("value",0);
	weapon->wield();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(WHT"尊者之袍"NOR, ({ "suit" }) );
	weapon->set("long","一件白色虎纹长袍。\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/music/qixianqin");
	weapon->set_name(RED"心焚琴"NOR, ({"tremor ting","ting" }) );
	weapon->set("long","一个暗红色的木琴。\n");
	weapon->set("value",0);

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

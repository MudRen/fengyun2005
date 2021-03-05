#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("天部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "男性" );
	set("nickname", HIR"杀心可息 降魔之心不可灭"NOR);
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(30) :),
	}) );

	set("combat_exp", 9000000);

	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","dagou-stick1",2);
	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIB"天魔圣甲"NOR, ({ "unholy armor","armor"}) );
	weapon->set("long","一件纯蓝色的外甲，不知是何物所制。\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/staff");
	weapon->set_name(HIW"打妖精棒"NOR, ({ "still killer"}) );
	weapon->set("long","一根森然白骨。\n");
	weapon->set("value",0);
	weapon->wield();

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

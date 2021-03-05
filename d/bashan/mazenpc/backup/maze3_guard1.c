#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("天部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "男性" );

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

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","daimonsword",4);
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIB"天魔圣甲"NOR, ({ "unholy armor","armor"}) );
	weapon->set("long","一件纯蓝色的外甲，不知是何物所制。\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/sword");
	weapon->set_name(HIW"白骨刺"NOR, ({ "unicorn spine","spine"}) );
	weapon->set("long","一根森然白骨。\n");
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
update /adm/daemons/smartd;update /std/char/npc_mid;update here;ask ke about silencer;call mingyue->delete_temp(inquiry_time);update /d/bashan/mazenpc/maze1_guard16;clone;call disciple->ccommand(kill fighter);
*/

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

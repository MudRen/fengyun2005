#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("天部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("nickname",HIR"两分钟一摘心 活活吓死你"NOR);
	set("gender", "女性" );

	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(20) :),
	}) );

	set("combat_exp", 9000000);

	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);


	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","daimonsword2",4);
	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIB"天魔圣甲"NOR, ({ "unholy armor","armor"}) );
	weapon->set("long","一件纯蓝色的外甲，不知是何物所制。\n");
	weapon->set("value",0);
	weapon->wear();


	weapon=carry_object("/obj/weapon/blade");
	weapon->set_name(NOR CYN"风神斩"NOR, ({"whole gale","gale" }) );
	weapon->set("long","这是一柄锋锐的长刀，刀柄上雕着小小的＂江门铸造＂四字。\n");
	weapon->set("value",0);
	weapon->wield();


}


/*
update /adm/daemons/smartd;update /std/char/npc_mid;update here;ask ke about silencer;call mingyue->delete_temp(inquiry_time);update /d/bashan/mazenpc/maze1_guard16;clone;call disciple->ccommand(kill fighter);
update /adm/daemons/smartd;update /std/char/npc_mid;update here;update /d/maze/npc/test;clone;update /d/bashan/mazenpc/maze2_guard6;clone;call disciple->ccommand(kill k);
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

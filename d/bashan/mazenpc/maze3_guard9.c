#include <ansi.h>
inherit SMART_NPC;


void create()
{
	object weapon;
	set_name("夜叉部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "女性" );
	set("nickname", HIR"人生能得几度狂"NOR);
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(100) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);


	auto_npc_setup("disciple",200,200,1,"/obj/weapon/","fighter_w","jin-gang",2);
	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(BLU"血魂之衣"NOR, ({ "cloth"}) );
	weapon->set("long","一件带有斑斑血迹的蓝衣。\n");
	weapon->set("value",0);
	weapon->wear();

}


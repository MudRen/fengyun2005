#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("紧那罗部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "男性" );
	set("nickname",HIR"唵 叭 嘛 咪 哞"NOR);
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(40) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_u","kwan-yin-spells",2);
	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("罗汉袈裟", ({ "monk cloth","cloth" }) );
	weapon->set("long","一件绘有九天魔像的奇异袈裟。\n");
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

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("龙部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "男性" );
	set("nickname",HIR"黑洞子里的一把火"NOR);
	
	set("attitude", "aggressive");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(30) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	set_skill("dragonwhip",180);
	set_skill("whip",200);
	set_skill("dodge",200);
	set_skill("fall-steps",200);
	set_skill("unarmed", 200);
	set_skill("spicyclaw",200);
	set_skill("divineforce",200);
	set_skill("xiaohun-whip",150);
	
	map_skill("parry","xiaohun-whip");
	map_skill("whip","dragonwhip");
	map_skill("force","divineforce");
	map_skill("unarmed","spicyclaw");
	map_skill("dodge","fall-steps");
		
	set("perform_weapon_attack","demon/whip/dragonwhip/thousandfeather");      
	set("perform_weapon_attack2","demon/whip/dragonwhip/firestorm");

	setup();
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIY"龙翔之服"NOR, ({ "dragon cloth","cloth"}) );
	weapon->set("long","一件黄色龙纹长服。\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/whip");
	weapon->set_name(HIR"火神鞭"NOR, ({ "whip"}) );
	weapon->set("long","一根长达数丈的赤红皮鞭。\n");
	weapon->set("value",0);
	weapon->wield();

	set_temp("apply/parry",200);
	set_temp("apply/attack",100);
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

// 第一下厉害。。。后来就不行了，最好2分钟内解决

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("天部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "男性" );
	set("nickname",HIR"两分钟一摘心 活活吓死你"NOR);
	
	set("attitude", "aggressive");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(30) :),
	}) );

	set("combat_exp", 9000000);

	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	set_skill("zen",200);
	set_skill("xiaodao",150);
	set_skill("demosword",150);
	set_skill("zensword",200);
	set_skill("sword",200);
	set_skill("dodge",200);
	set_skill("fall-steps",200);
	set_skill("unarmed", 200);
	set_skill("spicyclaw",200);
	set_skill("divineforce",200);

	map_skill("force","divineforce");
	map_skill("unarmed","spicyclaw");
	map_skill("dodge","fall-steps");
	map_skill("sword","demosword");
	map_skill("parry","zensword");

	set("perform_unarmed_attack","berserker/unarmed/spicyclaw/extrahit5");
	set("perform_unarmed_attack2","berserker/unarmed/spicyclaw/extrahit4");
	set("perform_unarmed_attack3","berserker/unarmed/spicyclaw/extrahit3");	
	set("perform_weapon_attack","huashan/sword/demosword/zhutianjianzhen");

	setup();

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
	int n;
	
	n = query_busy();
	stop_busy();
	
	::kill_ob(who);
	ccommand("perform force.wudumiaodi "+who->query("id"));
	
	perform_busy(n);
	
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

#include <ansi.h>
inherit CRAZY_NPC;

void create()
{
	object weapon;
	set_name("紧那罗部众", ({ "disciple" }) );
	set("title",YEL"大光明教"NOR);
	set("gender", "男性" );

	set("attitude", "aggressive");
	set("walk_area","shaolin");
	set("crazy_group","demon");

	set("no_busy",3);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(100) :),
	}) );

	set("combat_exp", 6000000);

	set("death_msg",CYN"\n$N低声道：生亦何欢，死亦何惧？莫若归去，莫若归去……\n"NOR);

	setup();
	add_money("coin" , 1+random(100));

	auto_npc_setup("disciple",200,220,0,"/obj/weapon/","fighter_w","fighter_w",2);

	set_skill("kongshoudao",200);
	map_skill("unarmed","kongshoudao");

	set("perform_unarmed_attack","ninja/unarmed/kongshoudao/yaozhan");      
	set("perform_unarmed_attack2","ninja/unarmed/kongshoudao/yaozhan");
	set("perform_unarmed_attack3","ninja/unarmed/kongshoudao/yaozhan");
	set("perform_busy_d","ninja/unarmed/kongshoudao/yaozhan");
	set("perform_busy_u",query("perform_busy_d"));

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("恶灵法袍", ({ "demon cloth","cloth" }) );
	weapon->set("long","一件绘有九天魔像的奇异袈裟。\n");
	weapon->set("value",0);
	weapon->wear();

	set_temp("apply/attack",200);
	set_temp("apply/parry",200);

	call_out("leave",300);
}

int leave()
{
	if (is_fighting() || query_temp("is_unconcious"))
	{
		call_out("leave",30);
		return 1;
	}
	message_vision(HIY"$N"HIY"打了个呼哨，迅速向外退却，很快就消失不见了。\n"NOR,this_object());
	destruct(this_object());
	return 1;
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

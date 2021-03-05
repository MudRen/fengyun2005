// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("阴涛", ({ "yin tao","yintao","yin","tao" }) );

		set("class","assassin");
		set("title",HIR BLK"鬼王"NOR);
//		set("nickname",BLU"分光捉影　一手七杀"NOR);

		set("always_duxin",1);

        set("gender", "男性" );

		set("age",47);

	set("chat_chance",1);
	set("chat_msg", ({
		"阴涛阴恻恻道：魔教使君此次传召，也不知又是什么晦气事情。\n",
	}) );

        set("combat_exp", 6100000);

		set("nb_chat_chance", 100);
		set("nb_chat_msg_combat", ([
			100: 	(: smart_fight() :),
		]) );

        set_skill("blade", 200);
        set_skill("sword", 200);
        set_skill("lefthand-sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("chillblade", 200);
        set_skill("13-sword", 200);
        set_skill("unarmed", 200);
        set_skill("spicyclaw", 350);

        map_skill("unarmed", "spicyclaw");
        map_skill("sword", "lefthand-sword");
        map_skill("parry", "lefthand-sword");
        map_skill("dodge", "13-sword");

		set("death_msg",CYN"\n$N大叫道：你～～～～～～～～！\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("碧嶙剑", ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();


        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("白麻长袍", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/hat");
        weapon->set_name("无常高冠", ({ "hat" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smart_fight()
{
	object me = this_object();
	object ob = select_opponent();
	int i,j;

	if (random(3))
		return 0;
	ccommand("perform duxin");
	return;
}


mapping ob_hit(object attacker, object victim,int damage)
{
	mapping data = ([]);
	if (!victim->is_busy() || victim->query_busy()<2)
		return 0;
	victim->stop_busy();
	victim->perform_busy(1);
	data["msg"] = CYN"$n白袍鼓动，借$N一击之力向后轻飘飘的退了开去。\n"NOR;
	return data;
}
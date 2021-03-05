// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
void smt_fight();
int look_stone();

void create()
{
	object weapon;
        set_name("四戒僧", ({ "shaolin monk","monk" }) );

        set("gender", "男性" );
		set("age",47);

        set("long","少林派的和尚。\n");

	set("no_fly",1);
	set("no_arrest",1);

//	set("nickname",MAG"绝情"NOR);
	set("title","少林第十二代弟子");

        set("combat_exp", 2900000);


	set("inquiry",([
		"请柬":		"为防奸人混入，唯有获请柬者可以参会。\n",
		"饮血平寇": (: look_stone :),
		]) );


        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smt_fight() :),
             }) );


	 set("npc_team","shaolin_blade");


        set_skill("blade", 300);
        set_skill("lianxin-blade", 300);

        map_skill("blade", "lianxin-blade");

		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name(YEL"和尚戒刀"NOR, ({ "blade" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("旧僧衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

void smt_fight()
{
	object *env, ob;
	int i;
	ob = this_object();
	env = all_inventory(environment(this_object()));
	for (i=0; i<sizeof(env);i++)
	{
		if (env[i]!= this_object() && env[i]->query("npc_team") == "shaolin_blade")
		{
			ob->ccommand("perform yipianlianxin with "+ env[i]->query("id")+ " 2");
			return;
		}
	}
	return;
}

void die()
{
	object me;
	me = query_temp("last_damage_from");
	if (!me)
		me=this_object();
	
	message_vision(CYN"\n$N对四戒僧冷笑道：中原正派，死不足惜。\n"NOR,me);

	REWARD_D->riddle_done(me,"杀和尚",0,1);


	::die();
	return;
}




int accept_object(object who, object ob)
{
	if (ob->query("name") == RED"饮血平寇大会请柬"NOR)
	{
		REWARD_D->riddle_done(who,"请柬",0,1);
		message_vision(CYN"四戒僧合十道：这位施主请进。\n"NOR,who);
	}
	return 1;
}




int look_stone()
{
	object me;
	int i;
	string msg;
	me=this_player();

	me->set("annie/a",1);

	message_vision(CYN"四戒僧说道：阿弥陀佛，施主需有"WHT"请柬"CYN"方能入内。\n"NOR,me);
	return 1;

}



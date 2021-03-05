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
		"高足":		"action四戒僧牛眼一瞪道：咋，你连师父是谁都不记得了？\n",
//		"饮血平寇": (: look_stone :),
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

	REWARD_D->riddle_done(me,"再杀和尚",0,1);

	::die();
	return;
}

int do_answer(string arg)
{
	object me = this_player();
	if (!me->query_temp("aaa"))
		return 0;
	me->delete_temp("aaa");
	if (arg == "九秀山庄" || arg == "九秀")
	{
		if (REWARD_D->check_m_success(me,"湖畔相会"))
		{
			REWARD_D->riddle_done(me,"托名九秀山庄",0,1);
			message_vision(CYN"\n四戒僧双手合十，躬身一礼：这位施主请进。\n"NOR,me);
			return 1;
		}
	}

	if (arg == "清平门下" || arg == "清平")
	{
		if (REWARD_D->check_m_success(me,"相会"))
		{
			REWARD_D->riddle_done(me,"托名清平",0,1);
			message_vision(CYN"\n四戒僧双手合十，躬身一礼：这位施主请进。\n"NOR,me);
			return 1;
		}
	}

	if (arg == "魔教" || arg == "西方魔教" || arg == "西方神教" || arg == "神教")
	{
		message_vision(CYN"\n四戒僧脸色一肃，大喝道：魔教妖人，胆敢放肆！\n"NOR,me);
		message_vision(CYN"\n四戒僧道：师弟，给我擒下了！\n"NOR,me);
		
		if (present("monk 2",environment(this_object())))
			present("monk 2",environment(this_object()))->kill_ob(me);
		if (present("monk 1",environment(this_object())))
			present("monk 1",environment(this_object()))->kill_ob(me);

		return 1;
	}

	// begger..没有人证明呀^^

	message_vision(CYN"\n四戒僧皱眉道：言语不尽不实，其中必定有鬼。\n"NOR,me);
	message_vision(CYN"\n四戒僧道：师弟，给我擒下了！\n"NOR,me);

		
		if (present("monk 2",environment(this_object())))
			present("monk 2",environment(this_object()))->kill_ob(me);
		if (present("monk 1",environment(this_object())))
			present("monk 1",environment(this_object()))->kill_ob(me);

	return 1;
}

void init()
{
	object ob;
	::init();
	add_action("do_answer","answer");
}


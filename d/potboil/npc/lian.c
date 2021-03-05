inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();

void create()
{
	object weapon;
    	set_name("莲", ({ "lian"}) );
    	set("nickname", BLU"辰"NOR);
    	set("gender", "女性" );
    	set("class","lama");

		set("title",YEL"大光明教"NOR);
    	set("reward_npc", 1);
    	set("difficulty", 6);
    	set("age", 34);
    	set("per", 35);

    	set("attitude","friendly");
		set("chat_chance_combat", 60);
    	set("chat_msg_combat", ({
        	(: smart_fight() :),
             }) );

    	set("combat_exp", 5100000);

        set_skill("unarmed", 250);
        set_skill("luoriquan", 350);
        set_skill("iron-cloth", 220);
        set_skill("xisui", 220);
        set_skill("magic", 220);
        set_skill("force", 220);
        set_skill("snowforce", 220);
        set_skill("music", 220);
        set_skill("blade", 220);
        set_skill("sword", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("chillblade", 220);
        set_skill("qiuzhi-sword", 180);
        set_skill("tie-steps", 160);
        set_skill("stormdance", 200);
        set_skill("lingxi-zhi", 200);
        set_skill("calligraphy",200);


        map_skill("iron-cloth", "xisui");
        map_skill("unarmed", "calligraphy");
        map_skill("blade", "chillblade");
        map_skill("magic", "music");
        map_skill("force", "snowforce");
        map_skill("sword", "qiuzhi-sword");
        map_skill("parry", "qiuzhi-sword");
        map_skill("dodge", "tie-steps");

        setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("荷叶滚边长裙", ({ "cloth" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->wear();


		weapon=carry_object("/obj/weapon/fist");
		weapon->set_name("青松笔", ({"pen" }) );
		weapon->set("long","");
		weapon->set("value",0);
		weapon->set("weapon_wielded","握");
		weapon->set("level_required",200);
		weapon->wield();
}

int kill_ob(object who)
{
	::kill_ob(who);
	if (is_busy())
		return 1;
	smart_fight();
	return 1;
}

void smart_fight()
{
	object ob,target;
	mapping buff;
	object *enemy;
	string msg;
	int i;
	object me = this_object();

	switch (random(4))
	{
	case 0:
		if (!present("定",environment()))
		{
			message_vision(MAG"\n莲笔法飞扬，转眼间已在地上描绘出一个大大的‘定’字。\n"NOR,me);
			target = new("/obj/treasure/npc/obj/ward2");
			target->move(environment());
			target->heal_ob(me,24);
			perform_busy(2);
			return;
		}
		break;
	case 1:
		if (!present("伤",environment()))
		{
			message_vision(RED"\n莲笔法飞扬，转眼间已在地上描绘出一个大大的‘伤’字。\n"NOR,me);
			target = new("/obj/treasure/npc/obj/ward3");
			target->move(environment());
			target->heal_ob(me,24);
			perform_busy(2);
			return;
		}
		break;
	
/*	if (!present("愈",environment()) && (query("kee") < query("max_kee") / 3 || query("gin") < query("max_gin") / 3 || query("sen") < query("max_sen") / 3))
	{
		message_vision(CYN"\n莲笔法飞扬，转眼间已在地上描绘出一个大大的‘愈’字。\n"NOR,me);
		target = new("/obj/treasure/npc/obj/ward");
		target->move(environment());
		target->heal_ob(select_opponent(),24);
		perform_busy(2);
		return;*/
	}
	if (is_busy())
		return;
	
	target = select_opponent();

	message_vision(WHT"\n$N陡然意兴大发，披头散发，手中兔毫笔一拢，将一篇羲之丧乱帖行云流水般一气呵成：\n",me);
	add_temp("apply/attack",150);
	add_temp("apply/damage",100);
	msg=HIC"羲之顿首－\n"NOR WHT"$N身形飘逸，势如笔刀，纵横之间四字清刚峭拔向$n刻去。"NOR;
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);

	msg=HIC"－丧乱之极，先墓再罹荼毒－－\n"NOR WHT"$N身形大开大阖，一笔一划尽是悲愤，狂风暴雨般洒向$n。"NOR;
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);


	msg=HIC"－－追惟酷甚－\n"NOR WHT"$N笔意陡变，出手迟缓凝重，似有千钧之力砸向$n！"NOR;
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);


	msg=HIC"－－－－号慕摧绝，痛贯心肝！\n"NOR WHT"$w"WHT"挥洒而成，其缩也凝重，似尺蠖之屈，其纵也险劲，如狡兔之脱！"NOR;
	COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);

	i=3;
	add_temp("apply/damage",-100);
	add_temp("apply/attack",-150);
	perform_busy(i);
	return;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

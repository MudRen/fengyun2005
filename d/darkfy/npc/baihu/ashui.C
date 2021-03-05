//Tushen@Fygroup
//Based on Silencer's code.Copyrights all reserved.
inherit SMART_NPC;
#include <ansi.h>
void smart_fight();

void create()
{
        set_name("阿水", ({ "ashui" }) );
        set("gender", "男性");
        set("age", 31);     
      	set("chat_chance", 1);
	set("chat_msg", ({
"阿水邪恶的笑了起来。\n",
	}) );
        set("attitude", "friendly");
        set("title",HIW"白虎"NOR);
        set("nickname", HIG"水漫金山"NOR);
        set("score", 200000);
        set("reward_npc", 1);
		    set("difficulty",50);
		    set("class","baiyun");
        set("death_msg",CYN"\n$N诧道：我日。。。这样也能死。\n"NOR);
        set("combat_exp", 16000000);        
        
    set("perform_busy_d", "bat/dodge/fengyu-piaoxiang/zonghengsihai");
		set("perform_weapon_attack", "baiyun/magic/music/bainiao");
		set("perform_weapon_attack2", "baiyun/magic/music/guanglingsan");
		set("perform_unarmed_attack", "baiyun/unarmed/calligraphy/sangluan");
		set("perform_buff_1", "berserker/force/gaunforce/damageup");
		set("perform_buff_2", "berserker/force/gaunforce/powerup");
		  set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
          
        set_skill("move", 270);
        set_skill("perception", 300);
        set_skill("force", 270);
        set_skill("spells", 300);
        set_skill("unarmed", 280);
        set_skill("parry", 300);
        set_skill("dodge", 280);
        set_skill("magic", 300); 
        
        set_skill("gaunforce", 180);
		    set_skill("fengyu-piaoxiang", 200);
        set_skill("heavendance", 230);
        set_skill("music", 200);
        
        map_skill("force","gaunforce");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("move","fengyu-piaoxiang");
        map_skill("parry","calligraphy");
        map_skill("magic","music");
        mao_skill("unarmed","calligraphy");
        setup();

    	carry_object("/obj/weapon/fist",([	
    						"name":  "狼毫",
    						"long": "恩，没想好写什么。\n",
    						 ]))->wield();  
    						 
    	carry_object("obj/music/chunlei");
    	
    	carry_object("/obj/armor/cloth",([	
    						"name":  "西装",
    						"long": "一件款式奇特的衣服，据说来自西域。\n",
    						 ]))->wear();  
}
void smart_fight()
{
	object ob,target;
	mapping buff;
	object *enemy;
	string msg;
	int i;
	object me = this_object();

	set("atman",query("max_atman")*2);

	switch (random(4))
	{
	case 0:		
		if (!present("定",environment()))
		{
			message_vision(MAG"\n阿水笔法飞扬，转眼间已在地上描绘出一个大大的‘定’字。\n"NOR,me);
			target = new(__DIR__"obj/ward2");
			target->move(environment());
			target->heal_ob(me,10);
			return;
		}
		break;
	case 1:
		if (!present("伤",environment()))
		{
			message_vision(RED"\n阿水笔法飞扬，转眼间已在地上描绘出一个大大的‘伤’字。\n"NOR,me);
			target = new(__DIR__"obj/ward3");
			target->move(environment());
			target->heal_ob(me,10);
			return;
		}
		break;
	
	}

	if (!present("愈",environment()) 
		&& (query("kee") < query("max_kee") / 3 || query("gin") < query("max_gin") / 3 || query("sen") < query("max_sen") / 3))
	{
		message_vision(CYN"\n阿水笔法飞扬，转眼间已在地上描绘出一个大大的‘愈’字。\n"NOR,me);
		target = new(__DIR__"obj/ward");
		target->move(environment());
		target->heal_ob(select_opponent(),8);
		return;
	}

	
	// CDT 10 sec 's single perform
	if (query("timer/pfm/pfm_huibi") + 10 < time()) {
		
		set("timer/pfm/pfm_huibi",time());		
		target = select_opponent();
		message_vision(WHT"\n$N陡然意兴大发，披头散发，手中狼毫一拢，将一篇羲之丧乱帖行云流水般一气呵成：\n",me);
		add_temp("apply/attack",100);
		add_temp("apply/damage",150);
		msg=HIC"羲之顿首－\n"NOR WHT"$N身形飘逸，势如笔刀，纵横之间四字清刚峭拔向$n刻去。"NOR;
		COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);

		if (me->query_busy())	// parry/dodge/ob_hit busy
		{
			message_vision(HIG"$N行动滞阻，笔法依旧轻灵，洋洋洒洒毫不受制。\n"NOR,me,target);
			me->stop_busy();
		}

		msg=HIC"－丧乱之极，先墓再罹荼毒－－\n"NOR WHT"$N身形大开大阖，一笔一划尽是悲愤，狂风暴雨般洒向$n。"NOR;
		COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);
	
		if (me->query_busy())	// parry/dodge/ob_hit busy
		{
			message_vision(HIG"$N行动滞阻，笔法依旧轻灵，洋洋洒洒毫不受制。\n"NOR,me,target);
			me->stop_busy();
		}

		msg=HIC"－－追惟酷甚－\n"NOR WHT"$N笔意陡变，出手迟缓凝重，似有千钧之力砸向$n！"NOR;
		COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);
	
		if (me->query_busy())	// parry/dodge/ob_hit busy
		{
			message_vision(HIG"$N行动滞阻，笔法依旧轻灵，洋洋洒洒毫不受制。\n"NOR,me,target);
			me->stop_busy();
		}

		msg=HIC"－－－－号慕摧绝，痛贯心肝！\n"NOR WHT"$w"WHT"挥洒而成，其缩也凝重，似尺蠖之屈，其纵也险劲，如狡兔之脱！"NOR;
		COMBAT_D->do_attack(this_object(),target,TYPE_PERFORM,msg);

		add_temp("apply/damage",-150);
		add_temp("apply/attack",-100);
	
	}
		
	return;
}


inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();

void create()	
{
    object weapon;

		set_name("左轻候", ({ "zuo qinghou","boss","zuo","qinghou"}) );
		set("gender", "男性" );
		set("nickname",BLU"点墨"NOR);
    	set("title","掷杯山庄庄主");
		set("class","annie");

		set("long","左轻候是个懂得享受生命的人，他不求封侯，但求常乐，所以自号为“轻侯”
。江湖人只知左轻候厨艺妙绝天下，一手阴柔掌法鲜人匹敌，却没有人知道
他的笔法也是登峰造极。\n");

		set("spawn_location","/d/baiyun/yinxian");
        set("gender", "男性" );
       
        set("gold", 20);
		set("agi", 60);
		
		set("real_boss",1);
		set("boss",1);	// immune to some rascal skill and ghostcurse.
						// busy resist but not immune.

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 4100000);	// L90. CAP @ L75.
    
        set_skill("unarmed", 240);
        set_skill("calligraphy",240);
        set_skill("parry",200);
        set_skill("dodge",200);
        set_skill("feixian-steps",160);
        
        map_skill("dodge","feixian-steps");
        map_skill("unarmed", "calligraphy");
		
		set("max_kee",50000);
		set("max_gin",45000);
		set("max_sen",45000);
    	    
		setup();

		weapon = carry_object("/d/huashan/npc/obj/qingcong");
		weapon->set_name(YEL"兔毫笔"NOR, ({ "brush pen" }) );
		weapon->set("unit", "杆小小的");
		weapon->set("long", "\n");
		weapon->set("weapon_wielded","握");
		weapon->wield();

		weapon=carry_object("/obj/armor/cloth");
		weapon->set_name(WHT"沾满墨迹的白衣"NOR, ({ "cloth" }) );
		weapon->set("long","沾满墨迹的白衣(Cloth)。");
		weapon->set("value",0);
		weapon->wear();
		
		set("drop/fixed_amount",1);
		set("drop/fixed_drop", ({		// L70-80 books
			BOOKS"class/xueyeqianzong_feline_2",	
			BOOKS"class/cloud-dance_yegui_2",
			BOOKS"class/dragonstrike_zjbl_3",
			BOOKS"class/dream-herb_huanmengluo_2",
			BOOKS"class/iceheart_buffup_3",
			BOOKS"class/kwan-yin-spells_ma_2",
			BOOKS"class/qidaoforce_juxue_2",
			BOOKS"class/xuezhan-spear_liguang_2",	
		}));
		
	set("drop/bg",0);
	set("drop/common",100);
	set("drop/rare",0);	
	set("drop/amount",3);
	set("drop/common_drop",({
"/obj/generate/surcoat_90_6.c",
"/obj/generate/surcoat_90_18.c",
"/obj/generate/cloth3_90_6.c",
"/obj/generate/cloth1_90_16.c",
"/obj/generate/boots_90_17.c",
	}) );
	set("drop/rare_drop",({
"none",
	}) );

}


void die()
{
	object who = query_max_damage_dealer();
	object lotus;
	
	if (random(2)) {
		lotus = new(AREA_XINJIANG"obj/lotus");
		if (lotus) lotus->move(this_object());
	}

	if (!objectp(who))
		who = query_temp("last_damage_from");
		
	if (objectp(who))
		ANNIE_D->generate_drop_item(this_object(),who);
	::die();
	return;
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
			message_vision(MAG"\n左轻候笔法飞扬，转眼间已在地上描绘出一个大大的‘定’字。\n"NOR,me);
			target = new(__DIR__"obj/ward2");
			target->move(environment());
			target->heal_ob(me,10);
			return;
		}
		break;
	case 1:
		if (!present("伤",environment()))
		{
			message_vision(RED"\n左轻候笔法飞扬，转眼间已在地上描绘出一个大大的‘伤’字。\n"NOR,me);
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
		message_vision(CYN"\n左轻候笔法飞扬，转眼间已在地上描绘出一个大大的‘愈’字。\n"NOR,me);
		target = new(__DIR__"obj/ward");
		target->move(environment());
		target->heal_ob(select_opponent(),8);
		return;
	}

	
	// CDT 10 sec 's single perform
	if (query("timer/pfm/pfm_huibi") + 10 < time()) {
		
		set("timer/pfm/pfm_huibi",time());		
		target = select_opponent();
		message_vision(WHT"\n$N陡然意兴大发，披头散发，手中兔毫笔一拢，将一篇羲之丧乱帖行云流水般一气呵成：\n",me);
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


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/


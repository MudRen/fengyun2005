#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","三脚拳");
	set("type","unarmed");
	set("effective_level",100);
	set("difficulty",200);
	set("practice_limit",30);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("skill_class","npc");
	set("parry_msg",			({
			"$n如同有「三只脚」一般，歪歪扭扭的闪了开去。\n",
			})
	);
	set("unarmed_parry_msg", 	({
			"$n如同有「三只脚」一般，歪歪扭扭的闪了开去。\n",
			})
	);
	action = ({
			([	"action":		"$N身子一歪，「左一拳」向$n打去",
				"dodge":		210,
				"parry":		210,
				"damage_type":	"瘀伤"
			]),
			([	"action":		"$N身子一倒，「右一拳」向$n打去",
				"dodge":		210,
				"parry":		210,
				"damage_type":	"瘀伤"
			]),
	});
}


mapping query_action(object me, object weapon) 
{
	int act;
	act=random(sizeof(action));
	me->set_temp("annie/birdiestrike",act+1);
	return action[act];
}

mixed hit_ob(object me, object victim)
{
	int act, pro, dam,i;
	
	
/*	if (ANNIE_D->check_buff(me,"tx-turtle-stance")>0) {
			me->ccommand("say nope"); 
			return 0;	
	}*/
		
	act=me->query_temp("annie/birdiestrike");
	if (act == me->query_temp("annie/birdiestrike2") && victim == me->query_temp("annie/birdiestrike4"))
	{
		me->add_temp("annie/birdiestrike3",1);
		pro = me->query_temp("annie/birdiestrike3");
//		me->ccommand("say pro ="+pro);
		if (pro * 20 > me->query_skill("birdiestrike",1))
			pro = me->query_skill("birdiestrike",1)/20;
		// 20/40/60(res. 10lv)/80/100/120/140/160
		// 64/128/256/512/1024/2052/4108/8216
//		me->ccommand("say pro ="+pro);
		if (pro < 1)
			pro = 1;
		dam = 32;
		for (i=0; i<pro; i++)
			dam*=2;
				
		dam = COMBAT_D->magic_modifier(me, victim, "kee", dam);
		victim->receive_damage("kee",dam,me);
//		me->ccommand("say extra damage ="+dam);
		return HIG"随着$N的招式，一种柔韧至极的劲道传进$n的奇经八脉之中．．\n" NOR;
	}
	else
	{
		me->set_temp("annie/birdiestrike2",act);
		me->set_temp("annie/birdiestrike3",0);
		me->set_temp("annie/birdiestrike4",victim);
	}
	return 0;
}

int effective_level(object me)
{
	int skill,n;

	if (me && userp(me))
	{
		skill= me->query_skill("birdiestrike",1);
		if (skill <= 32)	return 200;	// enable 64
		if (skill <= 49)	return 205;	// enable 100
		if (skill <= 51)	return 210;	// enable 107 (research->)
		if (skill <= 61)	return 220;	// enable 134
		if (skill <= 99)	return 250;	// enable 247
		if (skill >= 161)	return 270;	// enable 432
	}
	return 220;
}

int skill_difficulty()
{
	object me = this_player();
	int skill,n;
	if (me && userp(me))
	{
		skill=this_player()->query_skill("birdiestrike",1);
		if (skill <= 41)
			return 300;
		if (skill <= 51)
			return 400;
		if (skill <= 61)	// 51-61 21470 pot
			return 500;		
		if (skill <= 99)	// 61-99 435740 pot
			return 600;
		if (skill <= 160)	// 99-160 253455 pot
			return 800;
		return 1000;			// 161-200 391300 pot
	}
	return 300;
}

int help(object me)
{
	write(@HELP   
三脚拳是一种奇特的拳法，它的招式很简单，只有两招：左一拳和右
一拳，但是当你用相同的招式连续击中对手时，便能造成额外的伤害。
额外伤害力=32*2^n （n为连续相同招式的数目）
这个n同时受到三脚拳等级的限制，n<=（三脚拳/20)
也就是说，如果你有二十级三脚拳，最多额外伤害=64
如果你有160级，则最多额外伤害=32*2^8=8192

三脚拳的系数随级别提高而提高，学习难度也逐步加大，但在某些区
间会有一些奇怪的低谷
武功系数：200(<=32)、205(<=49)、210(<=51)、220(<=61)、
250(<=99)、200(<=160)、270(>160)
学习难度：300(<=41)、400(<=51)、500(<=61)、600(<=99)、
800(<=160)、1000(>160)
HELP
    );
    return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

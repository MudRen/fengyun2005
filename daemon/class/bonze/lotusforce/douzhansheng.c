// Silencer @ FY4 workgroup. Aug.2004
//	提高精气神三分钟, 如果受伤情况下，就等于 heal.
//	三分钟其实不是buff延续时间，而是可再用的时间。

#include <ansi.h>
void remove_effect(object me, object caster);

int exert(object me, object target, int amount)
{
	int skill,gin, kee, sen, am1, ess;
	mapping buff;
	
	if(me->query("class")!="bonze")
		return notify_fail("只有兴国禅寺的弟子才能颂『斗战胜诀』！\n");

	skill = me->query_skill("lotusforce", 1);
	ess = me->query_skill("essencemagic",1);
	
	if(skill < 20) return notify_fail("『斗战胜诀』至少需要20级莲华心法！\n");
	if(ess < 20)	return notify_fail("『斗战胜诀』至少需要20级八识神通！\n");	

	if( target != me ) 
	return notify_fail("你只能提升自己的体能。\n");

	if (ANNIE_D->check_buff(me,"xg-up"))
		return notify_fail("你已经在运斗战胜诀中了。\n");

	if( (int)me->query("force") < 100 )   
		return	notify_fail("至少需要100点的内力。\n");
	me->add("force", -100);
	
//       L20     L70     L110    L150    L190

	if (ess < 70)		am1 = 500;
	else if (ess <110)	am1	= 1000; 
	else if (ess <150) 	am1	= 1500;
	else if (ess <190)	am1	= 2000;
	else				am1 = 2500;
		
	buff=
		([
			"caster":me,
			"who": me,
			"type":"xg-up",
			"att":"bless",
			"name":"莲华心法·斗战胜诀",
			"time":  180,
			"buff_msg":HIY"$N大喝一声"BRED"『临 兵 斗 者 皆 阵 列 于 前』"NOR+HIY"，金光顿现，神威凛凛！！\n" NOR,
			"disa_type": 2,
			"finish_function": (: remove_effect :),
		]);
		
	// Let's make it a hate_less self-heal	
	me->receive_fulling("kee", am1);
	me->receive_fulling("gin",500);
	me->receive_fulling("sen", 500);
		
	ANNIE_D->buffup(buff);
	return 1;
}

void remove_effect(object me, object caster)
{
	int gin, kee, sen, am1, am2, am3, ess;
	
	if (!me || !caster) return;
		
	ess = me->query_skill("essencemagic",1);
	
	if (ess < 70)		am1 = 500;
	else if (ess <110)	am1	= 1000; 
	else if (ess <150) 	am1	= 1500;
	else if (ess <190)	am1	= 2000;
	else				am1 = 2500;
	
	gin = (int)me->query("gin");
	kee = (int)me->query("kee");
	sen = (int)me->query("sen");

	if ( gin- 500 > 0)	me->set("gin", gin-500);
		else	me->set("gin",1);
	
	if ( kee -am1 >0 ) me->set("kee", kee -am1);
		else 	me->set("kee",1);
	
	if ( sen - 500 >0) me->set("sen", sen- 500);
		else	me->set("sen", 1);
			
}


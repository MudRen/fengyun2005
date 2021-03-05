//	Silencer@fy4 workgroup
// 『蟠龙锁关』：可在短期（十回合内）招架对手所有的招式。（150）


#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	object *ob;
	int extra, skill, duration, agi,atk;
	mapping buff;
	string msg;
	
	if (me->query("class")!= "fugui")
		return notify_fail("只有富贵弟子才能使用『蟠龙锁关』\n");

	if (me->query_skill("xuezhan-spear",1)<190 || me->query_skill("skyforce",1) < 160)
		return notify_fail("蟠龙锁关需要190级的血战枪法和160级的碧空心法。\n");
				
	if (ANNIE_D->check_buff(me,"feat"))
		return notify_fail("你已经在使用类似的武功了。\n");
		
	duration = me->query("timer/pfm/fg_shield")-time()+1800-F_ABILITY->check_ability(me,"plsg_add")*60;
    if (duration>0)
       	return notify_fail("你还需要等待"+(int)(duration/60+1)+"分钟左右才能再次使用蟠龙锁关。\n");
		
	if( !me->is_fighting() )
		return notify_fail("『蟠龙锁关』只能在战斗中使用。\n");

	if (userp(me))	{
		me->set("force", 0);
		me->set("force_factor",0);
	}
	
	msg = BRED + HIY "$N一声长笑，血战枪法展至极尽，幻出漫天枪影，正是一招『蟠龙锁关』。\n\n"NOR;
		
		buff =
		([
			"caster":me,
			"who":me,
			"type":"feat",
			"type2":"parryup",
			"att":"bless",
			"name":"蟠龙锁关",
			"buffup_name":"parry",
			"buffup_type":""+extra,
			"buffup_ratio":987654321,
			"time":20,
			"buff_msg": msg,
			"special_func":2,
		]);
		
	ANNIE_D->buffup(buff);
	me->set("timer/pfm/fg_shield",time());
	
	return 1;
}
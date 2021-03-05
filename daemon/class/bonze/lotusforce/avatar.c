// avatar buff


#include <ansi.h>
void remove_effect(object me, object caster);

int exert(object me, object target, int amount)
{
	int skill,duration, am1, ess;
	mapping buff;
	object *mem;
	string msg;
	
	if(me->query("class")!="bonze")
		return notify_fail("只有兴国禅寺的弟子才能颂『日月光佛』！\n");

	skill = me->query_skill("lotusforce", 1);
	ess = me->query_skill("essencemagic",1);
	
	if(skill < 150 || ess < 220) 
		return notify_fail("『日月光佛』至少需要150级莲华心法和220级八识神通！\n");

    duration = me->query("timer/pfm/xg_avatar")-time() + 1200;
	if (duration>0)
		return notify_fail("你还需要等待"+(duration/60)+"分钟左右才能再次使用『日月光佛』\n");
    		
	if(!target ) target=me;
	if(target!= me) {
		mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("你只能给同一队伍中的人使用『日月光佛』。\n");
	}
	
	if (ANNIE_D->check_buff(target,"xg-avatar"))
		return notify_fail("此人已经有类似的特技了。\n");

	if( (int)me->query("force") < 500 )   
		return	notify_fail("『日月光佛』至少需要500点的内力。\n");
	me->add("force", -500);
	
	msg = BRED +HIY"$N"BRED +HIY"双手合十，掌尖之处，瞬间璀璨，放射出万道金芒汇向$n"BRED +HIY"，金光中，$n"BRED +HIY"的脸色
似慈悲，似萧杀，慈悲作怜悯天下万物，萧杀为伏魔凶狠杀戮！！\n" NOR;
	
	message_vision(msg, me, target);
	
	amount = 20 + F_ABILITY->check_ability(me,"avatar_add");
	
	buff=
		([
			"caster":	me,
			"who": 		target,
			"type":		"xg-avatar",
			"att":		"bless",
			"name":		"莲华心法·日月光佛",
			"time":  	180,
			"buff_msg": "",
			"buff1": "apply/strength",
			"buff1_c": amount,
			"buff2": "apply/agility",
			"buff2_c": amount,
			"buff3": "apply/composure",
			"buff3_c": amount,
		]);
		
	ANNIE_D->buffup(buff);
	me->perform_busy(1);
	me->set("timer/pfm/xg_avatar",time());
	return 1;
}

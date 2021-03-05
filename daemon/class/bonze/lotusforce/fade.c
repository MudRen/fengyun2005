// avatar buff


#include <ansi.h>
int stone_done(object me, object caster);


int exert(object me, object target, int amount)
{
		int skill,duration, am1, ess;
		mapping buff;
		object *mem;
		string msg;
	
		if(me->query("class")!="bonze")
			return notify_fail("只有兴国禅寺的弟子才能颂『晦明隐』！\n");
	
		skill = me->query_skill("lotusforce", 1);
		ess = me->query_skill("essencemagic",1);
		
		if(skill < 150 || ess < 210) 
			return notify_fail("『晦明隐』至少需要150级莲华心法和210级八识神通！\n");
	
	    duration = me->query("timer/pfm/xg_preservation")-time() + 1200;
		if (duration>0)
			return notify_fail("你还需要等待"+(duration/60)+"分钟左右才能再次使用『晦明隐』\n");
    		
    	if( me->query("force") < 100 )
        	return notify_fail("『晦明隐』需要100点的内力。\n");
    	if (userp(me)) me->add("force", -100);

    	msg = HIG"$N凝神提气，一团绿芒乍出体内，整个人渐渐虚化．．．\n"NOR;
    	
    	me->add_temp("pfm/xg_preservation",3);
		buff =
			([
				"caster":me,
				"who":me,
				"type":"xg-detaunt",
				"att":"bless",
				"name":"莲华心法·晦明隐",
				"time":30,
				"buff_msg": msg,
				"finish_function": (: stone_done :),
		]);
		
		ANNIE_D->buffup(buff);
		me->set("timer/pfm/xg_preservation", time());
		return 1;
}

int stone_done(object me, object caster){
	me->delete_temp("pfm/xg_preservation");
	return 1;
}
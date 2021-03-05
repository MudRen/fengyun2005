// L185 recover 75%, otherwise 50% kee

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	int fix, lvl,duration,amount;
		
	if(me->query("class")!="yinshi")
		return notify_fail("只有帝王谷弟子才能施展『乾坤消』\n");
		
	lvl = me->query_skill("qiankunwuxing",1);
	if( lvl < 100  || me->query_skill("celecurse",1) < 100)
    	return notify_fail("『乾坤消』需要100级的乾坤无形和通天降！\n");
		
	duration = me->query("timer/pfm/dwg_destruct")-time() + 1800;
    if (duration>0)
       	return notify_fail("你还需要等待"+(int)(duration/60+1)+"分钟左右才能够再次使用乾坤消。\n");
	
	if( !target ) 
		return notify_fail("你要向谁施展『乾坤消』？\n");
		
	if (target->query("possessed")!=me)
		return notify_fail("『乾坤消』只能施展在你自己召唤出来的亡灵身上。\n");

	if( me->query("atman") < 100 )
                return notify_fail("『乾坤消』需要耗费100点灵力！\n");
  	if (userp(me))	me->add("atman", -100);
        
	msg = HIR"\n\n$N念起乾坤无形中的『乾坤消』,一道红光自$n的眉心射出，
光华四射，氤氲遍地，片刻，红光一闪注入$N顶门！\n\n"NOR ;
	message_vision(msg, me, target);
	
	if (lvl >= 185)			amount = me->query("max_kee")*3/4;
	else 					amount = me->query("max_kee")/2;
		
	me->receive_fulling("kee",amount);
	me->set("timer/pfm/dwg_destruct",time());
	target->die();
	if (me->query_skill("qiankunwuxing",1) < 200)	me->perform_busy(1);
	return 1;
}



// hippo @ fy2005 workgroup. 2010.03.07

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	mapping buff;
	int extra, duration, time;

	if(me->query("class")!="fugui")
    		return notify_fail("只有富贵山庄弟子才能使出『诱敌深入』。\n");

	if( ANNIE_D->check_buff(me,"fg-youdishenru") ) {
		return notify_fail("『诱敌深入』已在进行中。\n");
	}

	if( me->query_skill("xuezhan-spear",1) < 190 || me->query_skill("skyforce")< 160 ) {
		return notify_fail("『诱敌深入』心法需160级碧空心法和190级血战枪法。\n");
	}
	
	if( target != me ) 
		return notify_fail("『诱敌深入』只能自己领悟。\n");

	if( me->query("force") < 100 ) {
		return notify_fail("你至少需要花费100点内力。\n");
	}
	if( userp(me) ) {
		me->add("force",-100);
	}

	if( userp(me) ) {
		duration = me->query("timer/pfm/fg-youdishenru") + 600 - time();
		if( duration > 0 ) {
			return notify_fail(YEL"『诱敌深入』，还需等待"+duration+"秒。\n"NOR);
		}
	}
	
	me->set("timer/pfm/fg-youdishenru",time());
	
  buff =
		([
      "caster":me,
      "who":me,
      "type":"fg-youdishenru",
      "att":"bless",
      "name":"碧空心法·诱敌深入",
      "time":60,
      "buff_msg":HIY"$N"HIY"『诱敌深入』成功。\n"NOR,
      "disa_type":1,
      "disa_msg":RED"$N"RED"『诱敌深入』退却。\n"NOR,
    ]);
    ANNIE_D->buffup(buff);
    return 1;
}
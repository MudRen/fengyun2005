// hippo @ fy2005 workgroup. 2010.03.07

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	mapping buff;
	int extra, duration, time;

	if( me->query("class")!="bonze" ) {
		return notify_fail("只有兴国禅寺的弟子才能颂『战佛诵』！\n");
	}
	if( ANNIE_D->check_buff(me,"xg-cloudstaff-up") ) {
		return notify_fail("你已经在运『战佛诵』中了。\n");
	}
	if( ANNIE_D->check_buff(me,"manatwist") ) {
		return notify_fail("你正在施展『战佛诵』。\n");
	}
	//extra = me->query_skill("necromancy",1);
	if( me->query_skill("essencemagic",1) < 150 || me->query_skill("lotusforce")< 150 ) {
		return notify_fail("『战佛诵』心法需150级莲华心法和150级八识神通。\n");
	}
	
	if( target != me ) 
		return notify_fail("你只能提升自己的体能。\n");

	if( me->query("force") < 10 ) {
		return notify_fail("你至少需要花费10点内力。\n");
	}
	if( userp(me) ) {
		me->add("force",-10);
	}

	if( userp(me) ) {
		duration = me->query("timer/pfm/xg-cloudstaff-up") + 30 - time();
		if( duration > 0 ) {
			return notify_fail(YEL"『战佛诵』，还需等待"+duration+"秒。\n"NOR);
		}
	}
	
	ANNIE_D->debuff(me,"xg-heal-down");
	
	me->set("timer/pfm/xg-cloudstaff-up",time());
	
  buff =
		([
      "caster":me,
      "who":me,
      "type":"xg-cloudstaff-up",
      //"type2":"manatwist",
      "att":"bless",
      "name":"莲华心法·战佛诵",
      "time":10800,
      "buff_msg":HIY"$N"HIY"『战佛诵』激活。\n"NOR,
      "disa_type":1,
      "disa_msg":RED"$N"RED"『战佛诵』消散。\n"NOR,
    ]);
    ANNIE_D->buffup(buff);
    return 1;
}
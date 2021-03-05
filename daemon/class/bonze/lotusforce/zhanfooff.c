// annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>

int exert(object me, object target)
{
	mapping buff;
	int extra,ratio,delay;
	
	if(me->query("class")!="bonze")
		return notify_fail("只有兴国禅寺的弟子才能使用『战佛诵』。\n");
	
	extra=me->query_skill("lotusforce",1);
	if(extra<150)
		return notify_fail("需要150级莲华心法才能消散『战佛诵』状态。\n");

    if( !ANNIE_D->check_buff(me,"xg-cloudstaff-up")) 
       		return notify_fail("你不在运功中。\n");

	if(target && me!=target)
		return notify_fail("消散『战佛诵』只能用在自己身上。\n");
	
	if (me->query("timer/pfm/xg-heal-down") + 30 > time())
		return notify_fail("『战佛诵』消散每30秒只能使用一次。\n");
	
	ANNIE_D->debuff(me,"xg-cloudstaff-up");
	
	me->set("timer/pfm/xg-heal-down",time());
	buff =
		([
      "caster":me,
      "who":me,
      "type":"xg-heal-down",
      //"type2":"manatwist",
      "att":"curse",
      "name":"莲华心法·战佛诵·后遗症",
      "time":180,
      "buff_msg":HIY"$N"HIY"『战佛诵·后遗症』启动。\n"NOR,
      "disa_type":1,
      "disa_msg":RED"$N"RED"『战佛诵·后遗症』结束。\n"NOR,
    ]);
  ANNIE_D->buffup(buff);
	return 1;
}

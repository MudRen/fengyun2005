// annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>

int exert(object me, object target)
{
	int extra,ratio,delay;
	
	if(me->query("class")!="shaolin")
		return notify_fail("只有少林高僧才能使用易筋经的护体神功。\n");
	
	extra=me->query_skill("yijinjing",1);
	if(extra<100)
		return notify_fail("需要100级易筋经才能自由收发护体神功。\n");

    if( !ANNIE_D->check_buff(me,"forceshield")) 
       		return notify_fail("你不在运功中。\n");

	if(target && me!=target)
		return notify_fail("取消护体神功只能用在自己身上。\n");
	
	if (me->query("timer/pfm/yjj_off") + 60 > time())
		return notify_fail("易筋经每分钟只能收功一次。\n");
	
	ANNIE_D->debuff(me,"forceshield");
	me->set("timer/pfm/yjj_off",time());
	
	return 1;
}

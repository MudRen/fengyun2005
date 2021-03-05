#include <ansi.h>
#include <command.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl, extra;
	
	if (me->query_skill("bai-quan",1) < 100)
		return notify_fail("『静心法』需要100级的白家拳。\n");
	
	if( !target ) target = me;
	if(me->is_fighting() )
		return notify_fail("『静心法』不能在战斗中使用。\n");
	
	if (!target) target = me;
	if( target != me)
		return notify_fail("『静心法』只能对自己使用。\n");
		
	if (me->query("sen")< 300)
		return notify_fail("『静心法』至少需要300点心神。\n");
		
	lvl = me->query_skill("bai-quan", 1) > 200 ? 200: me->query_skill("bai-quan", 1);
	extra = me->query_skill("qingpingforce",1);
		
	msg = WHT "$N"NOR+WHT"静气平声，踏踏实实地施展了一趟白家拳。\n" NOR;
	
	me->receive_fulling("kee", lvl + extra, me);
	me->add ("sen", -300);
	message_vision(msg, me);
	me->start_busy(2);
	return 1;
}

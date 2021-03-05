// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	object qer;
	string qqq;

	int lvl=130;

	qqq="/d/maze/sl-entry";

	
	extra = me->query_skill("pathfinding",1);

	if (extra < lvl && userp(me))
		return notify_fail("需要至少"+lvl+"级的天路引归。\n");

	if (me->is_fighting())
		return notify_fail("你现在正在战斗，无法使用天路引归。\n");
			
msg=HIB"突然四殿佛唱一般轰隆隆巨响起来，逐渐又平息了下来。\n"NOR;

if (base_name(environment(me))[0..14] == "/d/maze/sl-maze")
{
	tell_object(me,msg+"\n");
	qer=find_object(qqq);
	if (!qer)
		qer=load_object(qqq);
	me->move(qqq);
}
else
	tell_object(me,HIG"你失败了。\n"NOR);


	me->perform_busy(3);


	return 1;
}




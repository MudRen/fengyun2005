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

	int lvl=110;

	qqq="/d/xiangsi/icecave";

	
	extra = me->query_skill("pathfinding",1);

	if (extra < lvl && userp(me))
		return notify_fail("需要至少"+lvl+"级的天路引归。\n");

	if (me->is_fighting())
		return notify_fail("你现在正在战斗，无法使用天路引归。\n");
			
msg=HIR BLK"\n冰洞里传来阵阵开裂的声音，措手不及间，你脚下的冰块突然粉
碎，将你自冰层上抛了下去．．．\n\n"NOR;


if (base_name(environment(me))[0..23] == "/d/xiangsi/icecave2-maze")
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




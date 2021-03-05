// invocation.c

inherit SSERVER;
#define MAX_GUARD 1
int cast(object me, object target)
{
	object soldier;
	int	spells,lvl,i;

	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");

    if(me->query("class")!="taoist")
		return notify_fail("只有三清宫的弟子才能够使用三清道术。\n");

    spells = me->query_skill("spells");

	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能召唤天将！\n");
    if( me->query_temp("max_guard") > MAX_GUARD )
		return notify_fail("你已经召唤太多天兵鬼卒了！\n");

	lvl=me->query_skill("necromancy",1);

	message_vision("$N喃喃地念了几句咒语。\n", me);
	
	seteuid(getuid());
	if(random(spells) > (spells/2))
		soldier = new("/obj/npc/heaven_soldier");
	else
			soldier = new("/obj/npc/hell_guard");
	soldier->move(environment(me));
	spells=spells/5*4;
	if (spells>300) spells=300;	
	soldier->invocation(me, spells);
	soldier->set("possessed", me);
	me->add_temp("max_guard",1);
	
	me->start_busy(1);
	return 1;
}

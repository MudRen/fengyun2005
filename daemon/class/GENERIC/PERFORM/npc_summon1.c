
inherit SSERVER;

int perform(object me, object target)
{
	object soldier;
	int	spells,lvl;
	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");

        spells = me->query_skill("spells");
        if(me->query_skill("sheolmagic",1) < 35 )
                return notify_fail("『怨灵召唤』需要35级的夜叉通灵法！\n");

	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能召唤护驾！\n");

	message_vision("$N喃喃地念了几句咒语，双手一挥，一团烟雾自地底升起！\n", me);
	me->set("timer/demon_guardian1",time());
	seteuid(getuid());
	soldier = new("/obj/npc/guardian1");
	soldier->move(environment(me));
	soldier->invocation(me, spells);
	soldier->set("possessed", me);
	me->perform_busy(2);
	return 1;
}



/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

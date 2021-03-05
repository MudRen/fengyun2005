#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	object soldier;
	int	spells,lvl;
	int duration, time;
	
       	if(me->query("class")!="demon")
		return notify_fail("只有魔教的弟子才能够使用夜叉通灵法。\n");

        spells = me->query_skill("spells");
        if(me->query_skill("sheolmagic",1) < 215 )
                return notify_fail("『魔神召唤』需要215级的夜叉通灵法！\n");
	time = 3600;
	if (!userp(me)) time = 60;
	duration = me->query("timer/demon_guardian5")+ time -time();
	if (duration>0)	
		return notify_fail("此召唤魔法还需等待"+ duration/60 +"分钟。\n");
		
	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能召唤护驾！\n");

	message_vision(HIB"$N"HIB"喃喃地念了几句咒语，双手一挥，一团烟雾自地底升起！\n\n"NOR, me);
	message_vision("		"BMAG YEL"★魔神召唤★\n\n"NOR,me);
	
	me->set("timer/demon_guardian5",time());
	seteuid(getuid());
	soldier = new("/obj/npc/guardian5");
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

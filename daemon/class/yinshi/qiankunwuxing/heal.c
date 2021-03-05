#include <ansi.h>
inherit SSERVER;
int conjure(object me, object target)
{
	string msg;
	int lvl,ap,dp;

	if(me->query("class")!="yinshi")
		return notify_fail("只有帝王谷弟子才能施展『乾坤愈』\n");
	
	if( me->query_skill("qiankunwuxing",1) < 150 || me->query_skill("celecurse",1) < 150)
                return notify_fail("『乾坤愈』需要150级的乾坤无形和通天降！\n");
	
	if( !target ) 
		return notify_fail("你要向谁施展『乾坤愈』？\n");
		
	if (target->query("possessed")!=me)
		return notify_fail("『乾坤愈』只能施展在你自己召唤出来的亡灵身上。\n");

	if( me->query("atman") < 150 )
                return notify_fail("『乾坤愈』需要耗费150点灵力！\n");
    if (userp(me))	me->add("atman", -150);
        
	msg = WHT "\n\n$N念起乾坤无形中的『乾坤愈』,三道白气从指尖射出，凝聚不散，
片刻，竟成一幼婴形，散入$n顶门！\n\n"NOR ;
	message_vision(msg+NOR, me, target);
	target->delete_temp("pfm/qiankun");
	target->set_temp("pfm/qiankun/heal_curse",1);
	target->set("title",WHT"借尸还魂"NOR);
	if (me->query_skill("qiankunwuxing",1) < 200)	me->perform_busy(1);
	return 1;
}
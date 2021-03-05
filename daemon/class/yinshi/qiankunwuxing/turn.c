#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	string msg;
	int lvl,ap,dp;

	if(me->query("class")!="yinshi")
		return notify_fail("只有帝王谷弟子才能施展『乾坤转』\n");
	
	lvl = me->query_skill("qiankunwuxing",1);
	if( lvl < 140  || me->query_skill("celecurse",1) < 140)
                return notify_fail("『乾坤转』需要140级的乾坤无形和通天降！\n");
	
	if( !target ) 
		return notify_fail("你要向谁施展『乾坤转』？\n");
		
	if (target->query("possessed")!=me)
		return notify_fail("『乾坤转』只能施展在你自己召唤出来的亡灵身上。\n");

	if( me->query("atman") < 100 )
    	return notify_fail("『乾坤转』需要耗费100点灵力！\n");
    if (userp(me))	me->add("atman", -100);
        
	msg = CYN"\n\n$N念起乾坤无形中的『乾坤转』,忽然异香扑鼻，白光闪处，一朵鲜花出
现在了眼前，顷刻，花儿四分五裂，化作数道幽幽青光注入$n顶门！\n\n"NOR ;
	target->delete_temp("pfm/qiankun");
	target->set_temp("pfm/qiankun/turn_curse",2);
	target->set("title",HIC"借尸还魂"NOR);
	message_vision(msg, me, target);
	if (me->query_skill("qiankunwuxing",1) < 200)	me->perform_busy(1);
	return 1;
}

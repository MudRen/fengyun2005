#include <ansi.h>
inherit SSERVER;
int conjure(object me, object target)
{
	string msg;
	int lvl,ap,dp;

	if(me->query("class")!="yinshi")
		return notify_fail("只有帝王谷弟子才能施展『乾坤乱』\n");
	
	if( me->query_skill("qiankunwuxing",1) < 170  || me->query_skill("celecurse",1) < 170)
                return notify_fail("『乾坤乱』需要170级的乾坤无形和通天降！\n");
	
	if( !target ) 
		return notify_fail("你要向谁施展『乾坤乱』？\n");
		
	if (target->query("possessed")!=me)
		return notify_fail("『乾坤乱』只能施展在你自己召唤出来的亡灵身上。\n");

	if( me->query("atman") < 150 )
        return notify_fail("『乾坤乱』需要耗费150点灵力！\n");
    if (userp(me))	me->add("atman", -150);
        
	msg = YEL"\n\n$N念起乾坤无形中的『乾坤乱』,数道黄烟自掌心升起，距地数尺，盘旋不散，
似有鬼神哭泣之声，片刻，黄烟注入$n顶门！\n\n"NOR ;
	message_vision(msg, me, target);
	target->delete_temp("pfm/qiankun");
	target->set_temp("pfm/qiankun/busy_curse",1);
	target->set("title",YEL"借尸还魂"NOR);
	if (me->query_skill("qiankunwuxing",1) < 200)	me->perform_busy(1);
	return 1;
}
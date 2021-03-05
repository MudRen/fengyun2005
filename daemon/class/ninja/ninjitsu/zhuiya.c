// Silencer @ FY4 workgroup. Aug.2004
/*	『追牙』〔zhuiya）：忍者的一大特长是追踪和暗杀，此忍技在
四周布下血雾，而后用敏锐的嗅觉追踪对手，当忍术级别高于对方隐身神
通时可使对手现形。（需100级） */


#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	
	object *inv;
	int lvl, i, num;
	
	lvl = me->query_skill("ninjitsu",1);	
	if (lvl < 100)
    	return notify_fail("追牙需要100级忍术。\n");
	
	if( me->query("atman") < 300 )
		return notify_fail("追牙需要300点的灵力！\n");
        if (userp(me))	me->add("atman", -300);
	
	message_vision(RED"一团血雾从$N手中撒出，无声无息地在半空中炸开。。\n"NOR,me);
	
	inv = all_inventory(environment(me));
	for (i=0;i<sizeof(inv);i++)
	{
		if( inv[i]==me ) continue;
		if( inv[i]->is_corpse() ) continue;
		if( !inv[i]->is_character()) continue;
		if(!COMBAT_D->legitimate_kill(me,inv[i]))	continue;
     	if( wizardp(inv[i]) && inv[i]->query("wiz_invis"))	continue;
        if (ANNIE_D->check_buff(inv[i],"invisible")>0) 
           {
           		message_vision(RED"$N未及闪避，已溅上了数滴血珠，一阵晕眩。\n"NOR,inv[i]);
                inv[i]->perform_busy(3);
                ANNIE_D->debuff(inv[i],"invisible");
           	    inv[i]->set("timer/no_shade",time());
           }	
    }
    return 1;
}        
                
                
	
	
	
	
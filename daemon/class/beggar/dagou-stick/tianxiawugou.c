// mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i, bonus, exp_bonus;
	
	object weapon, *enemy;
	
	if (me->query("class")!= "beggar")
		return notify_fail("『天下无狗』乃丐帮绝技。\n");
	
	if((int)me->query_skill("dagou-stick",1) < 125 && userp(me))
		return notify_fail("『天下无狗』需要125级的打狗棒法。\n");	

	if (me->query_skill_mapped("force") != "huntunforce")
		return notify_fail("『天下无狗』需要混沌心法的配合。\n");

	enemy=me->query_enemy();
	if(!sizeof(enemy))
		return notify_fail("『天下无狗』只能对战斗中的对手使用。\n");
	if(target)
		return notify_fail("这个绝招不需要指定使用对象！！\n");
		
	weapon = me->query_temp("weapon");

	extra = me->query_skill("dagou-stick",1);
		
	// Similar to Chuozijue, but no chance for 续貂
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*2);
	
	msg = HIR  "$N低喝一声『天下无狗』，内力聚于手中的"+ weapon->name() +"，"
+ weapon->name() + HIR"化成满天棍影，\n昏天黑地盖向周围每一个人！\n" NOR;
	message_vision(msg,me);
	
	for(i=0;i<sizeof(enemy);i++)
	{
		msg=HIY"$N"HIY"手中的$w"HIY"直取$n"HIY"的$l！！"NOR;
		me->set_temp("marks/pfm_dagou",1);
		COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
		me->delete_temp("marks/pfm_dagou");
	}
	
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*2);
	
	if (ANNIE_D->check_buff(me, "fastcast")>0)
		me->perform_busy(1);
	else
		me->perform_busy(2);

	return 1;
}

/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg,sk;
 object weapon; 
 int skill,ap,dp,tf;

 if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［破残式］只能对战斗中的对手使用。\n");
 skill = (int)me->query_skill("dugu-sword",1);
 if( skill < 200 && userp(me))
  return notify_fail("你的独孤九剑等级不够, 不能使用「破残式」！\n");
  if( me->query("force") < 1000 )
  return notify_fail("你的内力不够，无法运用「破残式」！\n");
 msg = HIW "$N神功妙悟，独孤九剑「破残式」以惊天之势向$n攻出。 \n";
  if(userp(me)) me->delete("force");
 ap =  (int) me->query("combat_exp")* skill/10;
 dp = (int) target->query("combat_exp");
 if(random(ap+dp) > dp) {
  if(userp(target)){
   weapon = target->query_temp("weapon");
   if(!weapon) sk= "unarmed";
   else sk= weapon->query("skill_type");
   tf = target->query_skill(sk,1);
   if(tf>=2)
   target->set_skill(sk,tf-1);  
  }
 msg += "$n大惊失色，心惊胆寒，但已经太迟了！\n" NOR;
 target->start_busy(2);
 }else {
 msg += "可是$n看破了$N的剑路，就地一滚，十分狼狈的躲过这一招。\n"NOR;
 me->start_busy(4);
 }
 message_vision(msg, me, target);
 return 1;
}

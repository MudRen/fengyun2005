// Silencer@fengyun workgroup	June.2005


#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    int skill, num, i, duration,title, orforce, force,timer, extra;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
	
    if (userp(me))
    if (me->query("family/master_id")!="master yue" 
        	|| me->query("class")!="official")
        	return notify_fail("只有岳飞的弟子才能使用『九曜星宮阵』。\n");
        	
	skill = me->query_skill("strategy",1);
	if (me->query_skill("strategy",1) < 230 || me->query_skill("leadership",1)< 230)
		return notify_fail("『九曜星宮阵』需要230级兵法和230级用人之技。\n");        		
	       
    extra = me->query_skill("unarmed");
	if (userp(me) &&extra < 220) 
		return notify_fail("『九曜星宮阵』需要220级有效少林长拳!\n");
	
	if (me->query_temp("weapon"))
		return notify_fail("『九曜星宮阵』的特技需要空手使用。\n");
	
	if (me->query_skill_mapped("unarmed")!="changquan")
		return notify_fail("『九曜星宮阵』的特技需要少林长拳做配合。\n");
			
    if (me->query_temp("guard_count")<2)
        	return notify_fail("你的护卫太少，列不出阵法耶。\n");
	
	timer = 900 - F_ABILITY->check_ability(me,"jiu_add")*60;
    duration = me->query("timer/pfm/yue-jiu")-time() + timer;
    if ( duration >0)
		return notify_fail("你还需要等待"+(int)(duration/60)+"分钟左右才能再次发动九曜星宮阵。\n");
	
    if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『九曜星宮阵』只能在战斗中使用。\n");
        	
	me->set("timer/pfm/yue-jiu",time());
    
    msg = BGRN + HIY "$N"BGRN + HIY"挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"九曜星宮之阵！\n" NOR; 	
  	message_vision(msg, me);		
  	
  	message_vision(WHT"只听鼓声大振，喊声大举，如天摧地塌，岳撼山崩，$N"WHT"飞身而出。\n"NOR, me); 	        
    me->set("timer/pfm/yue-jiu",time());
    
    target->set_temp("no_check_pfm_win",1);
	
	me->add_temp("marks/full_hit_damage",1);
	
	me->add_temp("apply/attack",extra*3/2);
	me->add_temp("apply/damage",extra);
	
	msg = HIY  "$N"HIY"使出少林长拳中的『玉环鸳鸯拳』，一招连环七式向$n"HIY"攻出！\n" NOR;
	message_vision(msg,me,target);
	msg = HIY  "上一拳！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	
        msg = HIY  "下一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "左一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "右一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "前一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "后一拳！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "最后再一拳！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->add_temp("apply/attack",-extra*3/2);
		me->add_temp("apply/damage",-extra);
        me->add_temp("marks/full_hit_damage",-1);
		
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		} 
		
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
	   
    return 1;
}
	
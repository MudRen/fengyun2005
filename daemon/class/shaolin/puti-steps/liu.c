// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int skill, num, i, duration, mod,add;
	string msg, msg1, name;
	object *env, *huwei, *enemy, goner, weapon;
	
	if (userp(me))
        if (me->query("family/master_id")!="master yue" 
        	|| me->query("class")!="official")
        	return notify_fail("只有岳飞的弟子才能使用『六子连芳阵』。\n");
        	
	skill = me->query_skill("strategy",1);

	if (me->query_skill("strategy",1) < 200 || me->query_skill("leadership",1)< 200)
		return notify_fail("『六子连芳阵』需要200级兵法和200级用人之技。\n");        		
	  
	    add = F_ABILITY->check_ability(me,"3_array_add",3)*4/10;     
    duration = me->query("timer/pfm/yue_array_busy")-time() + 10 -add;
	if (duration>0)
        return notify_fail("你需要等待片刻（"+ duration +"秒）才能再次变幻阵法。\n");
        
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『六子连芳阵』只能在战斗中使用。\n");
		
    if (me->query_temp("guard_count")<2)
       	return notify_fail("你的护卫太少，列不出阵法耶。\n");
        
    env = all_inventory(environment(me));
    huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2 :), me);
    
    if (!huwei || sizeof(huwei)<1)
    	return notify_fail("你身边的护卫太少，列不出阵法耶。\n");
    	
    goner = huwei[random(sizeof(huwei))];
	if (!goner->is_fighting(target))
		return notify_fail("你的护卫不在战斗中，无法发动『六子连芳阵』\n");
			
    if (target->is_busy())
		return notify_fail("对手已被困，应该使用攻击性的阵法！\n");
	
	mod = COMBAT_D->can_busy(me, target, "puti-steps");	
	if (!mod)
		mod = 10000;
			
    weapon = goner->query_temp("weapon");
	name = goner->query("name");
	if(weapon && weapon->query("skill_type") == "spear") msg1 = "连人带枪";
	else if ( weapon && weapon->query("skill_type") == "hammer") msg1 = "连人带锤";
	else	msg1 = "和身";
	
	msg = BGRN + HIY "$N"BGRN + HIY"挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"六子连芳之阵！\n" NOR WHT"
阵中杀出一将，白袍、白马、" + msg1 + "向" + target->query("name")+ "扑了上去。\n\n"NOR;; 	
  	
  	message_vision(msg, me);
  	
	me->set("timer/pfm/yue_array_busy",time());
  	
  	if (COMBAT_D->do_busy_attack( me, target, "puti-steps/liu", "step", 200, mod))
	{		
		message_vision(HIW"$N猝不及防，被$n撞了个正着，顿时被阵法趁势困住！\n"NOR,target, goner);
		target->force_busy(3);
	}
	else{
		message_vision(YEL"$N不慌不忙地闪开数尺，$n一头撞在了地上，阵法顿时大乱。\n"NOR, target, goner); 
		goner->die();
	}
  	
  	return 1;
}


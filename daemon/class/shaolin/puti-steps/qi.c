// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    int skill, num, i,m, duration, mod,apply, add;
	string msg, name;
	object *env, *huwei, weapon,ob;
	int j=0;
	
	if (userp(me))
        if (me->query("family/master_id")!="master yue" 
        	|| me->query("class")!="official")
        	return notify_fail("只有岳飞的弟子才能使用『七星斩将阵』。\n");
        	
	skill = me->query_skill("strategy",1);

	if (me->query_skill("strategy",1) < 210 || me->query_skill("leadership",1)< 210)
		return notify_fail("『七星斩将阵』需要210级兵法和210级用人之技。\n");        		
	  
	    add = F_ABILITY->check_ability(me,"3_array_add",3)*4/10;     
    duration = me->query("timer/pfm/yue_array")-time() + 10 -add;
	if (duration>0)
        	return notify_fail("你需要等待片刻（"+ duration +"秒）才能再次变幻阵法。\n");
        
    if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『七星斩将阵』只能在战斗中使用。\n");
		
    if (me->query_temp("guard_count")<2)
        	return notify_fail("你的护卫太少，列不出阵法耶。\n");
        
    env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2 
		&& $1->query("id")!="sishi" && $1->query("id")!="bodyguard" :), me);
	if (!sizeof(huwei))
		return notify_fail("你的护卫不在左近，无法发动『七星斩将陣』\n");
	
	for (i=0;i<sizeof(huwei);i++)
		if (huwei[i]->query_temp("is_unconcious") 
  			|| !huwei[i]->is_fighting(target) 
  			||  huwei[i]->is_busy()
  			|| !huwei[i]->query_temp("weapon"))	
  			continue;
  		else 
  			ob = huwei[i];
  	
  	if (!ob)  		
  		return notify_fail("你的护卫状态不佳，无法发动『七星斩将陣』\n");
  		
	msg = BGRN + HIY"$N"BGRN + HIY"挥动手中银枪，但见身后护卫移形换位，旌旗飘摇，鼓声阵阵，瞬间列出"HIW"七星斩将之阵！\n"NOR; 	
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
  	for (i=0;i<sizeof(huwei);i++) {
		if (huwei[i] == ob)	continue;
		message_vision(CYN""+huwei[i]->name()+"伸出左掌，搭于"+ ob->name()+"肩上。\n"NOR,me);	
  		j++;			
  	}
	
	// normally atk+375, dmg+750, maximum with 十面埋伏 atk+375, dmg+1250
  	ob->add_temp("apply/attack", skill*5/2);
  	ob->add_temp("apply/damage",j * skill);
// 	write("add + "+ j + "\n");
  	
	target->add_temp("buff/no_abs",1);
	
  	if (ob->query("skill")== "spear") {
  		ob->add_temp("apply/damage",j * skill);
  		SKILL_D("yue-spear")->perform_target(ob,"zonghengtianxia",target);
  		ob->add_temp("apply/damage",-j* skill);
//  		ob->ccommand("perform zonghengtianxia "+target->query("id"));
  	}
  	if (ob->query("skill")=="hammer") {
  		SKILL_D("liuxing-hammer")->perform_target(ob,"fanbei",target);
//  			ob->ccommand("perform fanbei "+target->query("id"));
  	}	

  	if (target) {
		target->add_temp("buff/no_abs",-1);
		if (!target->query_temp("buff/no_abs"))
			target->delete_temp("buff/no_abs");
	}
  		
  	ob->add_temp("apply/attack", -skill*5/2);
  	ob->add_temp("apply/damage",-j* skill);
	
	me->perform_busy(1);
    return 1;
}

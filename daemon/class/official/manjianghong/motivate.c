#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
    int skill, num, i, duration, mod;
	string msg, name;
	object *env, *huwei, *huwei1;
	
	if (userp(me))
    if (me->query("class")!="official")
        return notify_fail("只有官员才能使用『激励』。\n");
        	
	skill = me->query_skill("strategy",1);

	if (me->query_skill("strategy",1) < 50 || me->query_skill("leadership",1)< 50
		|| me->query_skill("manjianghong",1)<50 )
		return notify_fail("『激励』需要50级兵法、用人之技和满江红心法。\n");        		
	       
    duration = me->query("timer/pfm/gf_motivate")-time() + 10;
	if (duration>0)
        	return notify_fail("你需要等待片刻（"+ duration +"秒）才能再次使用激励。\n");
    
    if (me->query_temp("guard_count")<1)
        return notify_fail("你没带护卫，用不出此招。\n");
        
    if (!me->is_fighting())
		return notify_fail("此特技只能在战斗中使用。\n");
	
    env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2
			&& $1->query("id")!="bodyguard" && $1->query("id")!="sishi" :), me);
	if (!sizeof(huwei))
		return notify_fail("你的护卫不在左近。\n");
	
	huwei1 = filter_array(huwei, (: !$1->query_temp("is_unconcious") 
					&& $1->is_fighting() && !$1->is_busy() :), me);
	if (!sizeof(huwei1))
		return notify_fail("你的护卫都自顾不暇呢。\n");					
		
	if (me->query("family/master_id")=="master yin")
		msg = HIY "$N"HIY"扬声呼道：格杀逆贼，赏银千两，孩儿们给我上啊！！！\n"NOR;
	else
		msg = HIY"$N"HIY"沉声道：社稷存亡，匹夫有责，精忠报国，死而无憾！！！\n"NOR;
		
	message_vision(msg, me);
  	
  	me->set("timer/pfm/gf_motivate",time());
  	
  	if (!random(4) && me->query("family/master_id")=="master yin"){
  		message_vision(BLU"众侍卫你看看我，我看看你，一声没吭。\n"NOR, me);
  		return 1;
  	}
  		
  	i = random(sizeof(huwei1[i]));
  	 		
  	if (huwei1[i]->query("skill")=="hammer")
  		huwei[i]->ccommand("perform fanbei");
  	else if (huwei1[i]->query("skill")=="spear")
  		huwei[i]->ccommand("perform zonghengtianxia");
  	else
  		huwei[i]->ccommand("perform tianwaifeixian");
  		
  	if (!huwei[i] || huwei[i]->is_busy()) {
  			return 1;	// perform 后 busy 了或者死了
  	}
  	
  	message_vision(BLU"众侍卫似有所动。。。。\n"NOR, me);
    return 1;
}


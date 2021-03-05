// silencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int single_perform(object target, object me);
string *style = ({
HIW"天地合其德－－"+WHT"$N"+WHT"闪身一剑撇出，人也到了天枢空档，手中利刃直指$n！"NOR,
HIW"日月合其明－－"+WHT"$N"+WHT"脚踩地极位，左手诀一指一引，剑在右手振出一朵剑花刺向$n。"NOR,
HIW"四时合其序－－"+WHT"$N"+WHT"一剑挥出,看似缓慢而平平无奇，剑剑皆虚，又似剑剑皆实。"NOR,
HIG"\n鬼神合其吉凶－－"+HIM"森森剑影漫天飞舞，忽聚忽分八方游走，疾如迅雷狂泻，分打$n"+HIM"各处要害！\n"NOR});


int perform(object me, object target)
{
	string msg;
	int skill,extra,i,j,max_exp;
	object ob,*obs, *env, *myteam;

	if (me->query("class")!="wudang")
		return notify_fail("只有武当弟子才可以发动三才剑阵。\n");	
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『三才剑阵』只能对战斗中的对手使用。\n");
	
        if (!me->query_team()) { 
		single_perform(target, me);
               	return 1;
        	}
        	
	if (member_array(target,myteam=me->query_team())!=-1) 
		return notify_fail("你不能攻击队友。\n");
	
	obs = ({});
        env=all_inventory(environment(me));
        for (i=0;i<sizeof(env);i++) {
        	if (member_array(env[i],myteam)==-1) continue;
        	if (env[i]->is_busy()) continue;
        	if (env[i]->query_skill("taiji-sword",1)<50) continue;
        	if (env[i]->query_skill_mapped("sword") != "taiji-sword") continue;
         	if (!objectp(ob=env[i]->query_temp("weapon")))	continue;
        	if (ob->query("skill_type")!="sword") continue;        	
        	obs += ({ env[i] });
        	if (sizeof(obs)>=3) break;
        }
        
         
        if (sizeof(obs)<2) {
		single_perform(target, me);
               	return 1;
        }
        
        if(sizeof(obs) > 3 )
		return notify_fail("三才剑阵最多三个人！！\n");
	
	skill=me->query_skill("taiji-sword",1);
	if (skill<50 || me->query_skill("changelaw",1)<50)
		return notify_fail("发动三才剑法至少需要50级的太极剑法和易经。\n");
	
	
	message_vision(HIR+"\n\n$N"+HIR"手中本静止着的长剑，忽如灵蛇交剪而出，化作一片光幕，立时发动了三才剑阵！\n"NOR,me);
	
	for (i=0;i<sizeof(obs);i++) {
		if (obs[i]->query("combat_exp")>max_exp) 
			max_exp=obs[i]->query("combat_exp");
	}
	
	if (random(target->query("combat_exp"))<max_exp) {
		message_vision(BLU"$N"+BLU"大惊失色，只觉无数剑影如山崩海啸汹涌而来，剑气迫人肤发，劲道直迫内腑。\n",target);
		target->start_busy(1);
	}
	
	for(i=0;i<sizeof(obs);i++)
        {
		msg = style[i];
		extra = obs[i]->query_skill("taiji-sword",1);
		obs[i]->add_temp("apply/attack", extra);
	        obs[i]->add_temp("apply/damage", extra);
		COMBAT_D->do_attack(obs[i],target, TYPE_PERFORM,msg);
		obs[i]->kill_ob(target);	
		obs[i]->add_temp("apply/attack", -extra);
		obs[i]->add_temp("apply/damage", -extra);
	}
	
	if (sizeof(obs)==3 && me->query_skill("changelaw",1)>=100) {
		msg=style[3];
		message_vision(msg,me,target);
		for (i=0;i<sizeof(obs);i++) { 
			obs[i]->add_temp("apply/attack", extra);
	        	obs[i]->add_temp("apply/damage", extra);
			COMBAT_D->do_attack(obs[i],target,TYPE_REGULAR," ");
			obs[i]->add_temp("apply/attack", -extra);
			obs[i]->add_temp("apply/damage", -extra);
		}
	}
	
	for (i=0;i<sizeof(obs);i++) {
		obs[i]->force_busy(2);
		if (obs[i]->query("class")!="wudang" && target->query_busy()<2)	
			target->stop_busy();
	}
	return 1;
}

int single_perform(object target, object me) {
        int skill,law,max_exp,n,i;
        string msg;
        
        skill=me->query_skill("taiji-sword",1);
        law=me->query_skill("changelaw",1);
        
        if (law>=215) n=4;
                else if (law>=195) n=3;
	        else if (law>=185) n=2;
	        else {
	        	tell_object(me,"独力发动三才剑阵至少需要185级的易经。\n");
	        	return 1;
	        }
        
        if (skill<170) {
        	tell_object(me,"独力发动剑阵至少需要170级的太极剑法。\n");
        	return 1;
        }
        
        message_vision(HIR"\n\n$N"+HIR"突然化作数个人影，忽聚忽分八方游走，竟以一己之力发动了三才剑阵！\n"NOR,me);
	
	max_exp=me->query("combat_exp");
		
	if (random(target->query("combat_exp"))<max_exp) {
		message_vision(BLU"$N"+BLU"大惊失色，只觉剑影山崩海啸，剑气逼人肤发，直迫内腑。\n"NOR,target);
		target->start_busy(1);
	} else {
		message_vision(YEL"$N"+YEL"不慌不忙，身形晃动，正是剑阵之空门。\n"NOR,target);
		me->perform_busy(2);
		return 1;
	}
	
	for(i=0;i<n;i++)
        {
		msg = HIR +  style[i] + NOR;
		me->add_temp("apply/attack", skill);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->add_temp("apply/attack", -skill);
	}

	target->stop_busy();
	me->perform_busy(2);

	return 1;		                
}
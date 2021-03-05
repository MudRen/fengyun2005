
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void single_perform(object target, object me, int myexp, int skill);

int perform(object me, object target)
{
    	string msg;
    	int myexp, ownexp, ownskill;
 	int skill, gin_cost, i, extra, boosted, damage;
 	string *style = ({
	HIY"［休门］－ $N"HIY"身影从滚滚风沙中现出，攻向$n"HIY"的$l！"NOR,
	HIG"［生门］－ $N"HIG"招式连绵不绝，如江涛起浪将$n"HIG"迫得喘不过气来！"NOR,
	HIR"［伤门］－ $N"HIR"在剑鼓交鸣的巨响中向$n"HIR"猛扑过去！"NOR,
	HIC"［杜门］－ $N"HIC"欺身急进，气势如十万甲兵卷地而来！"NOR,
	HIM"［景门］－ $N"HIM"手中暗蓄内力，一团紫气隐隐点向$n"HIM"的$l！"NOR,
	HIB"［死门］－ $N"HIB"随着阵内的杀气冲天而起，身形闪动攻向$n！"NOR,
	HIC"［惊门］－ $N"HIC"手一扬，一股强大的震流，如电击一般飞向$n"HIC"的$l！"NOR,
	WHT"［开门］－ $N"WHT"如迅雷乍现，急取$n"WHT"的$l！"NOR});
	object ob,*obs,*myteam,*env;

 	skill = (int) me->query_skill("five-steps",1);
 	gin_cost = (int)me->query_int() + 45;
 	
 	if ((string)me->query("class") != "wudang")
  		return notify_fail(WHT"你不是武当弟子，不能演变『八阵图』。\n"NOR);

	if( !skill || (skill < 100))
  		return notify_fail(WHT"演变『八阵图』需要100级的五行身法！\n"NOR);
 	
 	if( !target ) target = offensive_target(me);
	if( !target
		|| !target->is_character()
		|| !me->is_fighting(target) )
        return notify_fail("『八阵图』只能对战斗中的对手展开。\n");
        
       	myexp = (int) me->query("combat_exp"); 	
       	
       /*Single player perform*/
        if (!me->query_team()) { 
		single_perform(target, me, myexp, skill);
               	return 1;
        	}
       
       	
	if (member_array(target,myteam = me->query_team())!=-1) 
		return notify_fail("你不能攻击队友。\n");

//	Here is the checking to exclude all that not satisfy the condition.	
	
	obs = ({});
        env=all_inventory(environment(me));
        for (i=0;i<sizeof(env);i++) {
        //	tell_object(me,"i = "+ env[i]->query("id") + "\n");
        	if (member_array(env[i],myteam)==-1) continue;
        	if (env[i]->is_busy()) continue;
        	if (!env[i]->query_skill("five-steps")) continue;
        	if (env[i]->query_skill_mapped("dodge") != "five-steps"
        		&& env[i]->query_skill_mapped("move") != "five-steps")	continue;
        	if (env[i]->query_skill("five-steps",1)<120) continue;
        	// Why we now require fight? Because, we don't want ppl using this to bypass legitimate check.
        	if (!env[i]->is_fighting(target))	continue;
        	obs += ({ env[i] });
        	if (sizeof(obs)>=8) break;
        }
        
        if (sizeof(obs)<2) {
		single_perform(target, me, myexp, skill);
               	return 1;
        }

		/* team perform*/
        	else { 
//===============Team==================================================
			tell_object(me, "??\n");
			if(skill<160) {
				single_perform(target, me, myexp, skill);
				return 1;
			}
			
			// confirm everyone using five-steps
			if(sizeof(obs) > 8 ) {
				single_perform(target, me, myexp, skill);
				return notify_fail("『八阵图』阵法最多八个人！！\n");
			}
			
			myexp =0;
			extra=0;
			
			for(i=0;i<sizeof(obs);i++)
			{
				myexp += (int) obs[i]->query("combat_exp");
				extra += (int) obs[i]->query_skill("five-steps");
			}
			ownskill=me->query_skill("five-steps");
			ownexp=me->query("combat_exp");
				
			message_vision(MAG"\n只见$N"NOR MAG"五行身法一变，阵中诸人竟按遁甲"YEL" 休、生、伤、杜、景、死、惊、开"MAG" 部好位置，衍出"WHT"「八阵图」"MAG"！\n"NOR, me);
                	target->set_temp("no_check_pfm_win",1);
                	
                	if ( random(myexp)*5/i + ownexp/2 > (int) target->query("combat_exp") ){
                		msg = HIR"$N"HIR"只觉森森杀气直透心头。惟见怪石磋峨，槎丫似剑，横沙立土，重叠如山。\n一时心胆皆寒，寸步难移！\n\n"NOR;
                		target->start_busy(2);
                		damage = ownskill + 3*random(extra)/i ;
                		damage = COMBAT_D->magic_modifier(me, target, "sen", damage);     
                		target->receive_damage("sen", damage,me);
                	}
                	else{
                		msg = HIW"\n$N脚踏生门，左转右闪抵挡『八阵图』的围困。\n"NOR;
                      	}
                	extra = extra/i ;     	
			message_vision(msg, target);
			
			for(i=0;i<sizeof(obs);i++)
        		{
				msg = HIR +  style[i] + NOR;
        			obs[i]->add_temp("apply/attack", extra/2);
        			obs[i]->add_temp("apply/damage", extra);
			//	obs[i]->kill_ob(target);	
				COMBAT_D->do_attack(obs[i],target, TYPE_PERFORM,msg);
				target->set_temp("skip_damage_record",1);
				obs[i]->add_temp("apply/attack", -extra/2);
				obs[i]->add_temp("apply/damage", -extra);
				obs[i]->perform_busy(3);
			}
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

			return 1;

//===============End Team==================================================
        	}
}

void single_perform(object target, object me, int myexp, int skill) {
                int damage;
                string msg = MAG"\n只见$N"NOR MAG"五行身法一变，竟按遁甲"YEL" 休、生、伤、杜、景、死、惊、开"MAG" 衍出"WHT"『八阵图』"MAG"！\n"NOR;
                msg += WHT"\n霎时间狂风大作，飞沙走石，遮天盖地。$n只觉涛声浪涌，有如剑鼓之声！\n"NOR;
                
                if (COMBAT_D->do_busy_attack( me, target, "five-steps/bazhentu", "step", skill *2, 10))
                {
                       	msg+= HIR"森森杀气直透$n心头，惟见怪石磋峨，槎丫似剑，横沙立土，重叠如山。\n$n一时心胆皆寒，寸步难移！\n\n"NOR;
                	target->start_busy(2);
               		me->perform_busy(3);
//			average 1500, lowest 1000, highest 2000                		                		
//			200*2 + 150
                	damage = skill*2 + F_LEVEL->get_level(myexp);
                	damage = COMBAT_D->magic_modifier(me, target, "sen", damage);      		
                	target->receive_wound("sen", damage, me);
                	
                	message_vision(msg, me, target);
                	COMBAT_D->report_status(target);
        		COMBAT_D->win_lose_check(me,target,1);
                }
                else {
                	msg+= HIW"\n$n脚踏生门，左转右转脱离了『八阵图』的围困。\n"NOR;
                	me->perform_busy(2);
                	message_vision(msg, me, target);
                }                
}
                      
                      
                      
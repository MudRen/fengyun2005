#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i,j,k,l,skill,damage;
	object weapon;
	object * enemy;
	string dot_owner, dir, index;
	
	if(!me->is_fighting())
		return notify_fail("「炎舞鞭烈」只能对战斗中的对手使用。\n");

	skill = me->query_skill("dragonwhip",1);
	if (skill < 165)
		return notify_fail("「炎舞鞭烈」需要至少165级的龙凤奇翔鞭法。\n");
	weapon = me->query_temp("weapon");

	enemy = me->query_enemy();

	message_vision( HIR "\n$N"HIR"手腕疾抖，长鞭渐渐化为一道在身边缠绕飞旋的圆弧，将众人笼于圈内。
只听得$N"HIR"一声猛然沉喝，鞭势盘卷收缩，火光乍现。\n"NOR,me,target);


		dot_owner = file_name(me);
    	sscanf(dot_owner,"%s#%s",dir,index);
    	dot_owner = me->query("id")+ index;
    	
   		me->add_temp("apply/attack", skill);
    	me->add_temp("apply/damage", skill*2);

	for(i=0; i<sizeof(enemy); i++)
	{
		if (me->is_busy())	break;
			
		target = enemy[i];
		target->add_temp("combat_no_report",1);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM);
		target->add_temp("combat_no_report",-1);
		
		if (!target->query_temp("damaged_during_attack"))
			message_vision(HIW"\n$n"HIW"气定神凝，丝毫不乱，在纷飞的星火中闪身而出。\n"NOR,me,target);
		else
		{
			message_vision(HIY"\n$n"HIY"闪躲不及，被长鞭狠狠抽中，血花自火焰中飞溅而出。\n"NOR,me,target);
			
			// first hit is random(skill*5) + random(skill*2.5), 
			// dot = random (180) * 5;
			
			damage = COMBAT_D->magic_modifier(me, target,"kee" , random(skill*5));
			target->receive_wound("kee", damage/2 ,me);		
			target->receive_damage("kee", damage ,me);
			
			if (!target->query_temp("dot/dragonwhip/firestorm/"+dot_owner))
			{
				call_out("dot",5, me,target,10,0, skill*5, dot_owner);  
				target->set_temp("dot/dragonwhip/firestorm/"+dot_owner,1);
			}
			COMBAT_D->report_status(target);
		}
	}

	me->add_temp("apply/attack", -skill);
	me->add_temp("apply/damage", -skill*2);
	me->perform_busy(2);
	return 1;
}

void dot (object me, object enemy, int total, int count, int amount, string dot_owner)
{
	int num;
	
		if (!me || !enemy || !enemy->is_fighting(me)) {
			if (enemy) {
				message_vision(WHT"$N身上的火焰终于渐渐熄灭了。\n"NOR,enemy);
				enemy->delete_temp("dot/dragonwhip/firestorm/"+dot_owner);
			}
			return;
		}
		
	message_vision(RED"$N"RED"身上烈焰四纵，熊熊燃烧，只痛得$N"RED"冷汗直冒。\n"NOR,enemy);
	num = COMBAT_D->magic_modifier(me, enemy,"kee", random(amount));
	enemy->receive_wound("kee",num/2,me);
	enemy->receive_damage("kee",num,me);
	
	count= count + 1;
	if (count<total) call_out("dot",5,me, enemy,total,count, amount, dot_owner);
		else {
			message_vision(WHT"$N身上的火焰终于渐渐熄灭了。\n"NOR,enemy);
			enemy->delete_temp("dot/dragonwhip/firestorm/"+dot_owner);
		}
	return ;
}


// 『漫天花雨』（mantianhuayu）：每40级增加一枚暗器，最多为五枚, 

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,i,bonus, chance;
	int num, j, count, twice, x;
	object weapon, *enemy;
	
	if(me->query_skill("tanzhi-shentong",1) < 80)
		return notify_fail("『漫天花雨』至少需要80级的弹指神通！\n");
	
	num = me->query_skill("tanzhi-shentong",1)/40;
	if (num > 5) num = 5;
	
	weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if (count < 10)
		return notify_fail("至少需要10枚暗器。\n");
		
	enemy=me->query_enemy();
	if(!sizeof(enemy))
		return notify_fail("『漫天花雨』只能对战斗中的对手使用。\n");
	if(target)
		return notify_fail("这个绝招不需要指定使用对象！！\n");
			
	msg = HIY"$N"HIY"双袖一扬，无数"+ weapon->name() + HIY"突然从袖中纷纷飞出，
化成"+HIC"  漫"+HIG"  天"+HIY"  花"+HIR"  雨"+NOR HIY" 散布空中，四面飞下！\n" NOR;
	message_vision(msg,me);
	if (userp(me))	weapon->set_amount(count-1);
	i = 0;
	x = 0;
	
	for (j=0; j<num;j++)
	{
		msg=YEL"$N"YEL"手中的$w"YEL"射向$n"YEL"的$l！！"NOR;
		COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
		if (!enemy[i]->query_temp("damaged_during_attack")) x++;
		if (i==sizeof(enemy)-1) i=0;
			else i++;
	}
	
	chance = F_ABILITY->check_ability(me,"huayu_add")+ F_ABILITY->check_ability(me,"3_huayu_add",3)*2;
//	CHANNEL_D->do_sys_channel("sys",sprintf("chance is %d",chance));
		
	if (me->query("class") == "huashan" 
			&& chance >random(200) ) {
		twice = 1;
		message_vision(HIY"\n$N身形一个转折，手中"+weapon->name()+ HIY "连连射出。。。\n\n"NOR,me);	
                i= sizeof(enemy)-1;
		for ( j = num; j>0; j--)
		{
			msg=YEL"$N"YEL"手中的$w"YEL"射向$n"YEL"的$l！！"NOR;
			COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
			if (!enemy[i]->query_temp("damaged_during_attack")) x++;
			if (i==0) i=sizeof(enemy)-1;
				else i--;
		}
	}

	if (x>0) {		// 也就是说，至少保证 400 damage
		msg = HIY"\n叮！叮！数声，寒芒一震，"+chinese_number(x)+"枚"+ weapon->name()
				+ HIY"居然倒飞过来，旋舞在$N"HIY"身畔。\n\n"NOR;
		message_vision(msg, me);
		me->set_temp("pfm/hs_mthy_shield",x);			
	}

	if (num>2) { 
		me->perform_busy(3);
	}
	else   
		me->perform_busy(2);
				
	return 1;
}



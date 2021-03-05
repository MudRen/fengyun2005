// Silencer@fengyun	June.2005

#include <ansi.h>
inherit F_CLEAN_UP;

string *event1_msg=	({
	"有相相不相，無相亦不相，離彼相不相，相為何所相。\n",
	"此生若未生，云何能自生，若生已自生，已生何用生。\n",
	"燈中自無闇，住處亦無闇，破闇乃名照，燈為何所照。\n",
	"有無一時無，離無有亦無，不離無有有，有則應常無。\n",
	"若信諸法空，是則順於理，若不信法空，一切皆違失。\n",
	"若以無是空，無所應造作，未作已有業，不作有作者。\n",
	"般若波羅蜜，實法不顛倒，念想觀已除，言語法皆滅。\n",
	"無量眾罪除，清淨心常一，如是尊妙人，則能見般若。\n",
});
	
int main(object me)
{
	int i, skill, amount;

	me = this_player();
	if (me->query("class")!="lama" && me->query("class")!= "shaolin"
		&& me->query("class")!= "bonze")
		return notify_fail("不是和尚念什么经？\n");
	
	// usually it should be around 200 - 400
	amount = me->query_skill("zen",1)
			+ me->query_skill("lamaism",1)
			+ me->query_skill("buddhism",1);
		
	if (amount < 150)
		return notify_fail("你对经文的了解太浅薄了。。。。\n");
		
	if( !me->is_fighting() )
		return notify_fail("诵经只能在战斗中使用。\n");
	
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	
/*	if( ANNIE_D->check_buff(me,"forceshield")) 
    	return notify_fail("你提着一口气，怎么念经啊。\n");*/
       		
	if (me->query_temp("timer/chanting"))
		return notify_fail("你已经在诵经了。\n");

	if( userp(me) && me->query("sen") < 150 )
		return notify_fail("诵经需要耗费150点心神。\n");
	if (userp(me))	me->receive_damage("sen", 150);
			
	me->start_busy(2);
	amount = amount/2;
	
	message_vision(HIR"$N一手持佛珠，一手两指轻触如结弥陀印，低颂佛号！\n" NOR, me);
    me->set_temp("timer/chanting",1);
	call_out("dot",6,me,7,0,amount);  
	return 1;
}

void dot (object me, int total, int count, int amount)
{
	int num, my_exp, his_exp, i, enhance;
	object *ob;
	
	if (!me)	return;
		
	ob = me->query_enemy();
	if (!ob || sizeof(ob)<1) {
		message_vision(WHT"$N合掌说道：“阿弥陀佛，施主可曾悟了？”\n"NOR,me);
		me->delete_temp("timer/chanting");
		return;
	}

	message_vision(WHT"$N念道："+event1_msg[count]+"\n"NOR,me);
	enhance = amount> 100 ? amount: 100;
	
    for(i=0; i<sizeof(ob); i++)   {
       	if (!living(ob[i])) continue;
		if (!ob[i]->is_fighting(me)) continue;
		if (environment(ob[i]) != environment(me)) continue;

		if (COMBAT_D->do_busy_attack(me, ob[i], "chant", "step", enhance, 10))
		{
			// for normal SL/DZ/XG, it's 100 + random(100);
			num = amount + random(amount);
			num = COMBAT_D->magic_modifier(me, ob[i], "sen", num);
			ob[i]->receive_wound("sen",num,me);	// Wound is not effective on NPCs
			
			// Every 3 turns 50% chance (same exp) it will add 400 + random(400) hate
			if (!userp(ob[i]))
				ob[i]->add_hate(me, num*3);		// chant will add *4 hate.
			
			tell_object(ob[i],RED"你觉得头痛欲裂，差点儿晕了过去。\n"NOR);
			COMBAT_D->win_lose_check(me,ob[i],num);			
    		}
    	}
    	
	count++;
	if (count<= total) call_out("dot",6,me,total,count, amount);
		else 
		{
			message_vision(WHT"$N合掌说道：“阿弥陀佛，施主可曾悟了？”\n"NOR,me);
			me->delete_temp("timer/chanting");
		}
	return ;
}


int help(object me)
{
    write( @HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : chant[0m
[0;1;37m────────────────────────────────[0m
念经是风云中少林、兴国、大昭独有的技能，
使用的条件为密宗佛法、大乘佛经、禅道的等级之和高于１５０。
对这三门经文的修习越深，念经的效果就越明显。

念经在战斗中有两大功效，

（１）对周围敌人的心神的最大值造成持续的伤害
（２）吸引周围敌人的注意力，佛曰：我不入地狱，谁入？

[0;1;37m────────────────────────────────[0m
HELP
        );
    return 1;
}




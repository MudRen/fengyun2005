// L60： 聚血：铁雪的LOH	cdt 60min

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object *mem, *enemy, target;
        int i, extra,duration, fix, add, qidao, dorm, stage;
        string msg, msg1;
        
		if(me->query("class")!="legend" && userp(me))
			return notify_fail("只有铁雪山庄弟子才能够使用『聚血诀』\n");

 		qidao = me->query_skill("qidaoforce",1);
 		dorm = me->query_skill("dormancy",1);
 		
 		if(qidao < 60)
			return notify_fail("『聚血诀』需要60级的棋道心法。\n");
			
 		if(me->query_skill_mapped("force")!="qidaoforce")
 			return notify_fail("『聚血诀』是棋道心法的口诀。\n"); 	
 	                    
       	// 60mins, feat -20mins, eventually=40min
        fix = 3600;
        add = F_ABILITY->check_ability(me,"juxue_add")*2;
        fix = fix - add *60;
        
        duration = me->query("timer/pfm/tx_juxue")-time()+ fix;
        if (duration>0)
        	return notify_fail("你还需要等待"+(int)(duration/60+1)+"分钟左右才能够再次使用聚血诀。\n");
        
        if (!arg)
        	return notify_fail("聚血诀已经可以使用了，但需要指定对象。\n");
        
        if (arg) { 
        	if(!objectp(target = present(arg, environment(me))))
				return notify_fail("这里没有这个人。\n");
			if( !target->is_character() || target->is_corpse() )
				return notify_fail("看清楚一点，那并不是活物。\n");
        } else
        	target = me;
        			
		if (userp(me) && !COMBAT_D->legitimate_heal(me,target))
			return notify_fail("你不能向此人使用聚血诀（江湖仇杀限制）\n");
	    
		if(target!= me) {
			mem = me->query_team();
			if (!pointerp(mem) || member_array(target,mem) == -1)
				 return notify_fail("你只能给同一队伍中的人疗伤。\n");
		}
	    
	    stage = me->query("scroll/dormancy_juxue")>0?
    			me->query("scroll/dormancy_juxue"): 1;
    
	    switch (stage) {
	    	case 1:		extra  = 2000; 	break;	// L60  qidaoforce
	    	case 2:		extra = 6000; 	break;	// L150 qidaoforce, L250 dormancy
	    	case 3:		extra = 12000; break;	// L150 qidaoforce, L290 dormancy
	    }
	    
	    if (qidao < 150)	    extra = 2000;
	    	    	    	
		msg1 = BRED + HIW"";
		msg = "聚血诀";
	
		me->set("timer/pfm/tx_juxue",time());
		target ->receive_fulling("kee",extra, me);
	
		if (target == me )
			message_vision( msg1 + "
$N使出一招"+msg+"，手臂颤动，犹如蜻蜓点水，一口气尚未换过，已点完自身
奇经八脉，脸色顷刻泛红，一身伤势已去了大半！\n"NOR,me);
		else
			message_vision( msg1 + "
$N使出一招"+msg+"，手臂颤动，犹如蜻蜓点水，一口气尚未换过，已点完$n
奇经八脉，$n脸色顷刻泛红，一身伤势已去了大半！\n"NOR,me,target);

		if (target!=me)
		if(target->is_fighting()) {
			enemy = target->query_enemy();
			for (i=0;i<sizeof(enemy);i++) {
				if (!enemy[i]->is_fighting(me)) {
					enemy[i]->kill_ob(me);
					me->kill_ob(enemy[i]);
				}
			}	
		}

 		return 1;       
}

int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	juxue <某人>[0m
[0;1;37m────────────────────────────────[0m   

聚血诀：铁雪山庄特技

铁少夫妇虽隐居铁雪山庄，仍时时教诲弟子需心怀正气，扶
助弱小，此聚血心法艰涩难练，需6０级棋道心法，可在短时
期内恢复自身或他人的气血值，不受忙乱影响。

聚血Ｉ：需６０级棋道心法，瞬间治疗２０００点气血
聚血ＩＩ：需领悟卷轴，瞬间治疗６０００点气血
聚血ＩＩＩ：需领悟卷轴，瞬间治疗１２０００点气血

聚血诀需要指定使用对象，如果不指定的话，会告诉你使用信息。
聚血诀每６０分钟使用一次

[0;1;37m────────────────────────────────[0m   

HELP
    );
    return 1;
}

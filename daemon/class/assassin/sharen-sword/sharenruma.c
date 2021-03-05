#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int target_perform(object me, object target);

string* where = ({
        "四白",        "地仓",        "大迎",        "峡车",        "头维",        "下关",
        "隐白",        "太白",        "商丘",        "地机",        "少海",        "通理",
		"神门",        "金律",        "玉液",        "鱼腰",        "百劳",        "百会",
		"灵台",        "膻中",        "命门",
});

int perform(object me, object target)
{
    	string msg;
    	int extra,i,j,lmt,damages,bell,chance;
    	object weapon;
    	object *enemy;
    
    	extra = me->query_skill("sharen-sword",1);
    	if ( extra < 100)
        	return notify_fail("『杀人如麻』至少需要100级的杀人剑法！\n");
        
    	enemy=me->query_enemy();
    	if(!sizeof(enemy))
		return notify_fail("『杀人如麻』只能对战斗中的对手使用。\n");

//    	if (me->query("bellicosity")<=100 && userp(me))
//    		return notify_fail("你的杀气不够高。\n");    
    
    	if (target && me->query_temp("jingxing/concentrate")) {
    		if( !target->is_character()
		|| !me->is_fighting(target) )
			return notify_fail("『杀人如麻』只能对战斗中的对手使用。\n"); 	
	   	target_perform(me,target);
	    	return 1;
    	}
    		
    	if(target)	return notify_fail("『杀人如麻』不需要指定使用对象！！\n");
        bell=F_ABILITY->check_ability(me,"ruma_add");
       // DEBUG_CHANNEL(bell);
    	if (me->query_temp("timer/sharen")+20-bell>time() && userp(me) 
    		&& ! me->query_temp("jingxing/concentrate"))
    		return notify_fail("你的杀气还需过一段时间才能重新聚集起来。\n");
	
    	weapon = me->query_temp("weapon");
    	if(extra <= 162)
    	{
	        damages = extra/4;
	        msg = HIY"\n$N"+HIY"凶性大发，手中的"+ weapon->name()+
	            HIY"狂风暴雨般地向$n"+HIY"卷来! " NOR;
			message_vision(msg,me,enemy[0]);
	        me->add_temp("apply/attack",damages);
	        me->add_temp("apply/damage",damages);
    	}
    	else
    	{          	chance = F_ABILITY->check_ability(me, "3_srrm_add", 3);
    	            if( random(100) < chance ) {
	      	damages = extra/2;
		} else {
			damages = extra/4;
		}
	
	        
//	        msg = HIY"\n$N"+HIY"杀气大盛，只见"+ weapon->name()+
//	            HIY"疾风骤雨般地向$n"+HIY"全身各大要穴刺到! " NOR;

			msg = HIY"\n$N"+HIY"的剑式陡然变得奇诡而狠辣，凌厉的剑光仿佛狂岚中飞卷的砂石，挟\n带着如同夜枭尖鸣般的锐啸之声指向$n"HIY"的诸身要穴！\n" NOR;

	        message_vision(msg,me,enemy[0]);
	        me->add_temp("apply/attack",damages);
	        me->add_temp("apply/damage",damages);
    	}
    
    	lmt = random(5)+3;
		if (extra>160 && lmt<5) lmt=5;
    	if ( me->query("fy41/jq_sharenruma") ) 
    		lmt = 7;
    		 
    	j=0;
    	for(i=1;i<=lmt;i++)
    	{
	    	if(extra <= 162)
		    	msg =  HIR "第"+chinese_number(i)+"剑！" NOR;
			else
				msg = HIR+where[(i-1)*3+random(3)]+"！"NOR;
        	COMBAT_D->do_attack(me,enemy[j],TYPE_PERFORM,msg);
        	if (j==sizeof(enemy)-1) j=0;
			else j++;
    	}
    	
    	me->add_temp("apply/attack",-damages);
    	me->add_temp("apply/damage",-damages);
    	
    	me->perform_busy(3);
    	me->set_temp("timer/sharen",time());

/*    	if(extra > 162)			a little too romantic for Jing :)
		{
			msg = MAG"\n剑光一闪即没，归于$N"MAG"掌中，登时风停树止，鸟寂林息，刚才的一切气\n象荡然无存，似乎只是你的一场幻梦。\n\n" NOR;
			message_vision(msg,me,enemy[0]);
		}*/

    	return 1;
}


int target_perform(object me, object target)
{
    	string msg;
    	int extra,i,j,lmt,damages,bell;
    	object weapon;
    	object *enemy;
    	    
    	extra = me->query_skill("sharen-sword",1);
    	weapon = me->query_temp("weapon");
    	if(extra <= 162)
    	{
	        damages = extra/4;
	        msg = HIY"$N"+HIY"凶性大发，手中的"+ weapon->name()+
	            HIY"狂风暴雨般地向$n"+HIY"卷来! " NOR;
	        message_vision(msg,me,target);
	        me->add_temp("apply/attack",damages);
	        me->add_temp("apply/damage",damages);
    	}
    	else
    	{
	        	damages = extra/4;
	        
//	        msg = HIY"$N"+HIY"杀气大盛，只见"+ weapon->name()+
//	            HIY"疾风骤雨般地向$n"+HIY"全身各大要穴刺到! " NOR;
			msg = HIY"\n$N"+HIY"的剑式陡然变得奇诡而狠辣，凌厉的剑光仿佛狂岚中飞卷的砂石，挟\n带着如同夜枭尖鸣般的锐啸之声指向$n"HIY"的诸身要穴！\n" NOR;

			message_vision(msg,me,target);
	        me->add_temp("apply/attack",damages);
	        me->add_temp("apply/damage",damages);
    	}
    	lmt = random(5)+3;
    	if (extra>160 && lmt<5) lmt=5;
    	 
    	for(i=1;i<=lmt;i++)
    	{
        	msg =  HIR "第"+chinese_number(i)+"剑！" NOR;
        	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);  
    	}
    
    	me->add_temp("apply/attack",-damages);
    	me->add_temp("apply/damage",-damages);  
    
    	if (userp(me)) me->add("bellicosity",-30);
    	
    	if (!me->query("fy41/jq_sharenruma") && userp(me)
    		&& !( wizardp(me) && me->query("fy41/wiz"))
    		)
    	    	me->perform_busy(4);
    	else
    		me->perform_busy(3);
    		
/*    	if(extra > 162)
		{
			msg = MAG"\n剑光一闪即没，归于$N"MAG"掌中，登时风停树止，鸟寂林息，刚才的一切气\n象荡然无存，似乎只是你的一场幻梦。\n\n" NOR;
	        message_vision(msg,me,enemy[0]);
		}*/

		return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

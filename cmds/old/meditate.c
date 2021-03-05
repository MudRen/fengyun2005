// meditate.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	int sen_cost=30, mana_gain;
    
    	seteuid(getuid());
	
	if (userp(me))
    		return notify_fail("此指令已被exercise取代，请help exercise \n");
	
    	if(environment(me)->query("no_fight"))
        	return notify_fail("你不可以在这里冥思。\n");
    	if( me->is_fighting() ) return notify_fail("战斗中冥思——找死吗？\n");
    	if( me->is_busy() )
        	return notify_fail("你上一个动作还没有完成，不能冥思。\n");
    
    	if( arg && !sscanf(arg, "%d", sen_cost) )
        	return notify_fail("你要花多少精神冥思？\n");
    
    	if( sen_cost < 10 ) return notify_fail("你最少要花 10 点「神」才能冥思。\n");
    
    	if( (int)me->query("sen") < sen_cost )
        	return notify_fail("你现在精神太差了，进行冥思将会迷失，永远醒不过来！\n");
    
    	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
        	return notify_fail("你现在身体状况太差了，无法集中精神！（气血值至少在70%以上）\n");
    
    	if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
        	return notify_fail("你现在身体状况太虚弱了，无法进入冥思的状态！（精力值至少在70%以上）\n");
    
    	write("你盘膝而坐，静坐冥思了一会儿。\n");
    
    	me->add("sen", -sen_cost);
    	me->start_busy(1);
    // This function ranged from 1 to 15 when sen_cost = 30
    	mana_gain = sen_cost * ((int)me->query_skill("spells")/10 
                            + (int)me->query_spi() ) / 30;
    	mana_gain = (mana_gain + random(mana_gain))/5;
    
    	if( mana_gain < 1 ) {
        	write("但是当你睁开眼睛，只觉得脑中一片空白。\n");
        	return 1;
    	}
    
    	me->add("mana", mana_gain );
    
    	if( (int)me->query("mana") > (int)me->query("max_mana") * 2) {
        	if( (int)me->query("max_mana") >=  ((int)me->query_skill("spells", 1) +
             			me->query_skill("spells")/5) * 5 ) {
            		write("你忽然觉得脑中一片混乱，似乎法力的提升已经到了瓶颈。\n");
            		me->set("mana", 2*me->query("max_mana"));
        	} else {
            		write("你的法力提高了！\n");
			me->add("max_mana", 1);
			me->set("mana", me->query("max_mana"));
        	}
    	}	
    	return 1;
}


int help(object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : meditate [<耗费「神」的量，预设值 30>][0m
[0;1;37m────────────────────────────────[0m 
静坐冥思，将游离的精神力有效地集中凝聚成能够用来施展法术的能量
，藉以增加自己的法力。

打坐得到的法力最大值 == 基本咒术等级*5 + 当前的有效咒术等级
举例:　咒术 (spells)                           - 深不可测 200
  　　 咒文 (spells)         ： 麻婆寒练术       有效等级：500  
法力最大值 = 200*5 + 500 = 1500

平均转化效率＝ （有效咒术等级／１０＋灵性）／１００

请参考 help attributes.txt 
相关指令：
	增加内力	ｅｘｅｒｃｉｓｅ	
	增加灵力	ｒｅｓｐｉｒａｔｅ
	
	恢复体力：	ｅｘｅｒｔ　ｒｅｃｏｖｅｒ
	恢复心神：	ｅｘｅｒｔ　ｒｅｆｒｅｓｈ
	恢复精力：	ｅｘｅｒｔ　ｒｅｇｅｎｅｒａｔｅ
[0;1;37m────────────────────────────────[0m
HELP
        );
    return 1;
}

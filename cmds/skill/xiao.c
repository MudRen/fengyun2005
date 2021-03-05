#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object wolf, *enemy;
	int summonwolf, exp, cost, hate, i, guard, duration, timer;
	        
    if ((string)me->query("class") != "wolfmount")
		return notify_fail("只有狼山弟子才可以驱狼助阵。\n");
        
    summonwolf = (int)me->query_skill("summonwolf",1);
	if(summonwolf < 20 )
    		return notify_fail("唤狼至少需要20级的唤狼之术！\n");   
        
    timer = 40;
	duration = me->query("timer/alert")-time() + timer - F_ABILITY->check_ability(me,"xiao_add");
    if ( duration >0)
		return notify_fail("你还需要等待"+(int)(duration)+"秒钟左右才能再次唤狼！\n");
		
    if (me->is_busy() )
        	return notify_fail("你现在正忙，无法驱狼助阵。\n");
    
    if(!me->is_fighting() )
        	return notify_fail("好象没有人要杀你！\n");
        	
	if (ANNIE_D->check_buff(me,"lockfield") >= 1)
	{
		tell_object(me,YEL"你张口欲啸，却突然发现发不出一点声音。\n"NOR);
		return 0;
	}
			
	if(me->query_temp("max_guard"))
        return notify_fail("附近的狼已经被你叫完了。\n");
             
	if (summonwolf<100)	cost = 80;
		else	cost = 80 + (summonwolf-80)/3;		
	if(me->query("sen")< cost ||me->query("gin") < cost)
		return notify_fail("你的精神状况太差了，恐怕无法有效的驱狼助阵。\n");
	me->receive_damage("sen",cost);
	me->receive_damage("gin",cost);
	
	if (summonwolf > 200)	summonwolf = 200;	// capped
		
	seteuid(getuid());
	wolf= new("/obj/npc/wolf");
	me->add_temp("max_guard",1);
	wolf->move(environment(me));
    wolf->invocation(me, (summonwolf));
    wolf->set("possessed", me);

	if (summonwolf<50)
		wolf->set_name("杂毛恶狼",({ "wolf" }));
	else if (summonwolf<75)
		wolf->set_name(WHT"灰毛恶狼"NOR,({ "wolf" }));
	else if (summonwolf<100)
    	wolf->set_name(YEL"黄毛恶狼"NOR,({ "wolf" }));
	else if (summonwolf<150)
        wolf->set_name(RED"红毛恶狼"NOR,({ "wolf" }));
	else if (summonwolf<200)
		wolf->set_name(HIW"白毛恶狼"NOR,({ "wolf" }));
    else if (summonwolf<250)
     	wolf->set_name(HIR"赤毛恶狼"NOR,({ "wolf" }));
	else 
		wolf->set_name(HIY"金毛狼王"NOR,({ "wolf" }));

    me->set("timer/alert",time());
                
    if (wolf)
    {       
	    enemy = me->query_enemy();
	    if (enemy)
	    for (i=0;i<sizeof(enemy);i++)
	    {
	       	hate = enemy[i]->query_hate(me);
	       	enemy[i]->add_hate(wolf, summonwolf + hate);     	
	    }   	
       	message_vision(HIB "\n$N仰天狼嚎“呜～嗷～～，呜～嗷”，顿时漫山遍野群狼齐哮。\n" NOR, me);	
    	message_vision( "\n\n$N恶狠狠地扑了上来。\n" , wolf);
    }
	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	指令格式：xiao[0m
[0;1;37m────────────────────────────────[0m   

指令格式：xiao
 
狼山弟子每二十个回合可唤狼来转移敌人注意力，至少需要20级唤狼术。
唤出的狼出现后将具有比主人略高的憎恨值，与主人并肩战斗10个回合后
消失。呼出狼的强弱取决于唤狼之术的级别、狼的属性与主人相似，但气
血较差。唤狼不能在自我忙乱时进行，同时将消耗一定的心神和精力。

[0;1;37m────────────────────────────────[0m    
HELP
    );
    return 1;
}

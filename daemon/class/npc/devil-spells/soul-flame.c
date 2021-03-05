// void_sense.c

#include <ansi.h>

inherit SSERVER;
int soul_flame(object me, object obj, int lvl, int counter);
int cast(object me, object target)
{
	int lvl,i, number;
	object env, *inv;
	if(me->query("class")!="npc" && userp(me))
		return notify_fail("只有荧河武士才可以使用青冥魔咒！\n");
		
        if((int) me->query_skill("devil-spells",1) < 200)
                return notify_fail("你的青冥魔咒不够高深！\n");
        if(! me->is_fighting() )
                return notify_fail("［魔火炼魂］只能在战斗中使用！\n");

        if( me->query_temp("marks/soul_flame") )
        	return notify_fail("你正在使用魔火炼魂！\n");
   	lvl = (int) me->query_skill("spells");

	message_vision(NOR CYN"$N面色阴沉如铁，口中喃喃念起咒语。缓缓将手举至胸前，作火焰升腾状。 \n" NOR, me);

	message_vision(HIB"无数幽幽的蓝火仿佛受到召唤从地下升腾而起， \n$N周围顿时变成了恐怖的人间炼狱。 \n"NOR, me);
        me->set_temp("marks/soul_flame", 1);
        if(target)
        	soul_flame(me, target, lvl, lvl/150);
        else
        {
        	env = environment(me);
        	inv = all_inventory(env);
        	for(i=0; i<sizeof(inv); i++) {
                	if( inv[i]==me ) continue;
                	if( inv[i]->is_corpse() ) continue;
			if( !inv[i]->is_character()) continue;
                	if( !inv[i]->is_fighting(me)) continue;              	
                	number++;
                	soul_flame(me, inv[i], lvl/number, lvl/100);
                	
        	}
        }
        
        me->start_busy(1);
        return 1;

}

int soul_flame(object me, object obj, int lvl, int counter)
{
        int ratio;
        
        if (!me || !obj)	return 1;
        if (counter<1) {
        	me->delete_temp("marks/soul_flame");
        	return 0;
        }
        
        if ( !objectp(obj) || ! obj->is_fighting() ){
        	me->delete_temp("marks/soul_flame");
        	return 0;
        }
                
        message_vision(NOR BLU "\n蠕动的蓝火从$N脚下蜿蜒游动而起。\n"NOR, obj);
        
        if(obj->is_zombie()==1) {
                message_vision(RED "$N发出一阵焦臭味道，顿时化成黑黑的木炭！\n" NOR, obj);
                obj->die();
                return 1;
        }
	ratio =  lvl*( me->query("combat_exp")/2 + random(me->query("combat_exp")))
			/ (10 + obj->query("combat_exp"))/260;
        if (ratio )  {
        	obj->set_temp("last_damage_from", me);
        	obj->receive_wound("gin",3*lvl/5+1, me);
		obj->receive_wound("kee",lvl +  50, me);
		obj->receive_wound("sen",4*lvl/7+1, me);
        	message_vision(HIC "\n一条条蠕动的蓝火如蟒蛇般缠上了$N。\n"NOR, obj);
        	COMBAT_D->report_status(obj);                                        
        } 
        else {
        	message_vision(HIY "\n$N腾身跃起，闪过了毒蛇般的火焰。\n"NOR, obj);
        }
        counter--;
        call_out("soul_flame", 2+random(2), me, obj ,lvl*2/3, counter);
        return 1;
}

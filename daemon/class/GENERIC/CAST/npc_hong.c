// void_sense.c

#include <ansi.h>

inherit SSERVER;
int bbqthem(object me, object obj);
int cast(object me, object target)
{
	int lvl,i,j,k;
	object env, *inv, *myteam;
	
	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");
	
	if(me->query("class")!="lama")
		return notify_fail("只有大昭寺的弟子才可以使用真言法术！\n");
                
	lvl = (int) me->query_skill("spells");

	message_vision(HIW "$N右手于胸前展成莲花之状，左手折腕向上势若莲台，沉于右手下，面容肃静念道：“吽” \n" NOR, me);
        message_vision(HIR "．．．只见$N双手一瞬间发出比太阳还要耀眼的光芒！！！\n" NOR, me);
        env = environment(me);

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( me->is_fighting(inv[i])) 
                	bbqthem(me, inv[i]);
        }
        me->start_busy(2);
        return 1;

}


int bbqthem(object me, object obj) 
{
	int spells, busy_num;
	string id_enemy;
	spells = (int) me->query_skill("spells");
	spells = spells+ random(spells);
        if(obj->query("combat_exp")>random(me->query("combat_exp")/100*spells))
        {
        	message_vision(HIB"$N连忙转过头去，不看$n。\n"NOR,obj,me);
        	obj->kill_ob(me);
        	me->kill_ob(obj);
        	return 1;
        }
	if(userp(obj) )
	{
	tell_object(obj,HIW"你只觉得眼前白茫茫的一片，什么都看不到了。。。\n"NOR);
	obj->add_temp("block_msg/all",1);
	obj->start_busy(2);
	message_vision(CYN"$N痛苦的捂住眼睛，直在地上打滚。\n"NOR,obj);
	me->kill_ob(obj);
	obj->kill_ob(me);
	call_out ("recover",12, obj);
	}
	else
	{
	if (obj->query("no_busy")) {
		busy_num = obj->query("no_busy");
		obj->delete("no_busy");
		call_out ("busy_recover",10, busy_num, obj);
		}
	obj->start_busy(2+random(3));
	message_vision(CYN"$N痛苦的捂住眼睛，直在地上打滚。\n"NOR,obj);
	obj->kill_ob(me);
	me->kill_ob(obj);	
	}
	return 1;
}


int recover (object obj)
{
	if (obj->query_temp("block_msg/all")>=1)
	    	obj->add_temp("block_msg/all", -1);
	tell_object(obj, HIG"慢慢慢慢的，你的眼睛开始可以分辨周围的事物了。\n" NOR);
	return 1;
}	

int busy_recover (int busy_num, object obj)
{
	obj->set("no_busy",busy_num);
	return 1;
}	

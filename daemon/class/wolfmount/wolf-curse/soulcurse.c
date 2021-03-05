// a skill to set others/self back to death-gate.

#include <ansi.h>
inherit SSERVER;

int curse(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;
    if(me->query("class")!="wolfmount")
		return notify_fail("只有狼山弟子才能使出『离魂咒』\n");
       
    if(me->query_skill("cursism",1) < 120 || me->query_skill("wolf-curse",1)< 120
        	|| me->query_skill("summonwolf",1)<220)
    	return notify_fail("『离魂咒』需要120级的天狼血咒和降头术，220级的唤狼术！\n");

	if((int)me->query("kee") < 1000 )
	return notify_fail("『离魂咒』需要耗费１０００点的气血！\n");
	write("你想使谁离魂？");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
	
}

void select_target(object me, string name)
{
	mapping ob_list;
    	object ob,new1;
	string msg;
	object room,corpse;
	string *list;
	object *inv;
	int i,level;
    if( !name || name=="" ) {
    	write("\n中止施法。\n");
        return;
    }

    ob = find_living(name);
	room = environment(me);
	
	if (room->query("no_fly")) {
		tell_object(me,"此地无法使用离魂咒。\n");
		return;
	}
	
	if( !ob  || !present(ob, room)){
		write("\n有这个人吗？\n");
		return; 
	}	
	if(ob->is_ghost() || ob->is_corpse())		{
		write("\n你只能对活物下『离魂咒』\n");
		return;
	}
	if (!userp(ob)){
	   	write("\n你只能对玩家下『离魂咒』\n");
	   	return;
    }
    
    if (!ob->team_member(me)) {
    	write("\n你只能向队友使用离魂咒。\n");
    	return ;
    }
    
    if (me->is_fighting() || ob->is_fighting()){
    	tell_object(me,"战斗中不能使用离魂咒。\n");
    	return;
    }
    
    if (ob==me) {
    	tell_object(me,"对自己怎么能使用离魂咒呢？\n");
    	return;
    }
    
    if (stringp(ob->query_temp("no_move"))) {
		tell_object(me,"此人无法离开当前场所。\n");
		return;	
	}		
	
	if (me->query("kee")< 1000 || me->query("eff_kee")<1000)
	{
		tell_object(me,"你的气血太低，若用此术恐怕自己先离魂了。\n");
		return;
	}		    
    if (userp(me))	me->receive_wound("kee",1000);
    if (ob!=me) msg = HIB "\n$N对$n悲声低吟：生亦何欢。。死亦何苦。。莫若归去。。。\n\n" ;
		else msg = HIB "\n$N悲声低吟：生亦何欢。。死亦何苦。。莫若归去。。。\n\n" ;
	
	me->start_busy(2);
	
  	level = me->query_skill("cursism");
	if( random(level)>level/2) 
	{
		if (ob!=me){
			msg +=  "$n忽然倒了下来，头上冒出一阵浓雾，浓缩成一个黑影，但很快就消失了。\n" NOR;
			message_vision(msg, me,ob);
		}	else 
		{
			msg +=  "$N忽然倒了下来，头上冒出一阵浓雾，浓缩成一个黑影，但很快就消失了。\n" NOR;
			message_vision(msg, me);
		}

		ob->move("/d/death/gate");
		return;
	}
	else
		msg += "结果什么也没有发生\n"NOR;
	
	if (ob !=me) message_vision(msg, me,ob);
		else message_vision (msg,me);
	
}


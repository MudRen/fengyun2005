// TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
    string msg;
    int ap, dp,myexp;
    
    if((int)me->query_skill("charm", 1) < 120 )
	        return notify_fail("你的魅术不够高！\n");
    if(!me->is_fighting())
	return notify_fail("现在没有必要可怜兮兮地抛媚眼! \n");
    if( !target ) target = offensive_target(me);
    
    if( !target
	||!target->is_character()
	||target->is_corpse()
	||target==me)
        return notify_fail("你要对谁施展这个法术？\n");

    if((int)me->query("mana") < 100 )
        return notify_fail("你的法力不够！\n");

    if((int)me->query("sen") < 50 )
        return notify_fail("你的精神没有办法有效集中！\n");

    me->add("mana", -100);
    me->receive_damage("sen", 50);
    
    if( random(me->query("max_mana")) < 30 )
    {
        write("你失败了！\n");
        return 1;
    }

    msg = MAG "$N星眸微开，媚态万千，如清雅的雪莲沾上了无边的妖艳，诱惑着$n！\n\n" ;
    
    ap = me->query_skill("charm",1);
    myexp = me->query("combat_exp");
    ap = ( ap * ap * ap/40 ) * (int)me->query("per") ;
    dp = target->query("combat_exp");
	if (target->query("gender") != me->query("gender"))
	{		
		if( (random(ap + dp) > dp) && (random(myexp) > dp/2) )
		{
			msg +=WHT "$n不由痴了，浑然忘记了一切。 \n";
			//if( me->is_fighting() )
				//target->increase_action(-50);
				target->remove_killer(me);
				me->remove_killer(target);
		}
		else  
		{
			msg += WHT "但是$n不为所动。\n";
			me->start_busy(4);
		}
	}
	else
	{
		//will never success on same gender while target not homo
		msg += YEL "但是$n对$N丝毫不感兴趣。\n";
		me->start_busy(4);
	}
     message_vision(msg+NOR, me, target);
    return 1;
}

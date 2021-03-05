// Silencer@fengyun	June.2005
// 5 mins per use.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int main(object me, string arg)
{
	int skill, duration;
	object target;
	string msg;
	
 	seteuid(getuid());
	if(me->query("class") != "shenshui") 
		return	notify_fail("假死是神水宫的绝技！\n");
	
	if (me->is_ghost())
		return notify_fail("你已经不是活人了。\n");
		
	//  normally it's 900-600 = 300=5 min, 
	skill = me->query_skill("nine-moon-spirit",1);	
	duration = me->query("timer/jiasi") - time() + 900 - F_ABILITY->check_ability(me, "jiasi_add")*60;
	if (duration > 0)
	   	return notify_fail(WHT"需要等待" + duration + WHT"秒左右，现在旧技重演会被看穿的！\n");
    	  	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("你不在战斗中，不需要假死。\n");

	message_vision(WHT"\n$N"NOR+WHT"惨叫一声，一头栽倒在地下。。。。。\n"NOR,me);
        
    // Some attacks don't set this mark... mostly spells.    
    if (me->query_temp("last_damage_time") + 4 < time())
    {
		message_vision(HIR"$N"HIR"大笑道：“没碰到就死了，佩服佩服！！！”\n"NOR, target);
		me->perform_busy(1);
		me->set("timer/jiasi",time());
		tell_object(me, RED"（你假死的把戏被人识破了！！！）\n"NOR);
		return 1;
	}
	message_vision("\n$N死了。\n",me);	
	
    me->set("disable_type",HIG "<假死中>" NOR);
    me->remove_all_killer();
	me->remove_all_enemy();
    me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me :), 60);
    me->set_temp("disable_inputs",1);
    me->set_temp("block_msg/all",1);
	me->set_temp("is_unconcious",1);
	me->set_temp("in_jiasi",1);
	return 1;
}

void remove_dazuo(object me)
{
   	me->delete_temp("in_jiasi");
   	me->delete_temp("is_unconcious",1);
   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");
   	me->delete_temp("block_msg/all");
   	message_vision("$N在地上悄悄地翻了个身，小心翼翼地睁开了眼。\n",me);
	me->set("timer/jiasi",time());
}




int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	jiasi[0m
[0;1;37m────────────────────────────────[0m   

神水宫绝技，在绝境中假装死亡欺骗对手，创造逃生的机会。
注意：你的对手也不是傻子，运用此绝技须抓准时机，唯有
在被敌人伤害后的2回合内才能生效，否则莫名其妙死了可骗
不到人。

[0;1;37m────────────────────────────────[0m   

HELP
        );
        return 1;
}
 

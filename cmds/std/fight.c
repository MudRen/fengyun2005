// fight.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 06/28/2001 by Daniel Q. Yu.
//

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;
	seteuid(getuid());
	
	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻击谁？\n");
	
	if( !wizardp(me) && environment(me)->query("no_fight") && !obj->query("practice_dummy"))
		return notify_fail("这里禁止战斗。\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "已经无法战斗了。\n"); 

	if(obj==me)	return notify_fail("你不能攻击自己。\n");
	if( userp(obj) ){
		if((object)obj->query_temp("pending/fight")!=me ) {
			message_vision("\n$N对著$n说道：" 
				+ RANK_D->query_self(me) 
				+ me->name() + "，领教"
				+ RANK_D->query_respect(obj) 
				+ "的高招！\n\n", me, obj);
			if( objectp(old_target = me->query_temp("pending/fight")) )
				tell_object(old_target, YEL + me->name() + "取消了和你比试的念头。\n" NOR);
			me->set_temp("pending/fight", obj);
			tell_object(obj, YEL "如果你愿意和对方进行比试，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 fight 指令。\n" NOR);
			write(YEL "由於对方是由玩家控制的人物，你必须等对方同意才能进行比试。\n" NOR);
			return 1;
		} else {
			message_vision("\n$N对著$n说道：" 
					+ RANK_D->query_self(me) 
					+ me->name() 
					+ "，领教" + RANK_D->query_respect(obj) 
					+ "的高招！\n\n", me, obj);
			me->fight_ob(obj);
			obj->fight_ob(me);
		}
	} else {
		if( obj->query("can_speak") ) {
			message_vision("\n$N对著$n说道：" 
					+ RANK_D->query_self(me) 
					+ me->name() + "，领教"
					+ RANK_D->query_respect(obj) 
					+ "的高招！\n\n", me, obj);
			if( !userp(obj) && !obj->accept_fight(me) ) {
				tell_object(me,"看起来" + obj->name() + "并不想跟你较量。\n");
				return 1;
			} else {
				me->fight_ob(obj);
				obj->fight_ob(me);
			}
		} else {
			if (!COMBAT_D->legitimate_kill(me, obj)) {
				if (stringp(obj->query("NO_KILL")))
					return notify_fail(obj->query("NO_KILL"));
			}
			message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);
			me->fight_ob(obj);
			obj->kill_ob(me);
		}
	}
	return 1;
}
int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	 fight <人物>[0m
[0;1;37m────────────────────────────────[0m   
 
这个指令让你向一个人物「讨教」或者是「切磋武艺」，这种形式的战斗
纯粹是点到为止，因此不会致命，但是并不是所有的NPC 都喜欢打架，因
此有许多时候你的比武要求会被拒绝。要注意的是，即使在比武中，偶尔
也会有出手过重而致人死亡之例。
 
其他相关指令: kill

PS. 如果对方不愿意接受你的挑战，你仍然可以迳行用 kill 指令开始
	战斗，有关 fight 跟 kill 的区分请看 'help combat'.

[0;1;37m────────────────────────────────[0m   

HELP
    );
    return 1;
}
 

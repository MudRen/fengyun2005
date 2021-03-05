// kill.c
// Modified by justdoit at Dec 5,2001
// When player type kill,KILL_LOG file will add user id in it.

#include <ansi.h>
inherit F_CLEAN_UP;
int legitimate_kill(object attacker, object victim);

int main(object me, string arg)
{
	object obj;
	string /**killer,*/ callname;
	seteuid(getuid());

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准战斗。\n");

	if( !arg )
		return notify_fail("你想杀谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj==me)
		return notify_fail("用 suicide 指令会比较快:P。\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, obj)) {
		if (stringp(obj->query("NO_KILL")))
			return notify_fail(obj->query("NO_KILL"));
		if (stringp(obj->query("NO_PK")))
			return notify_fail(obj->query("NO_PK"));	
		else 
			return notify_fail("你无法攻击此人。\n");
	}
	
	callname = RANK_D->query_rude(obj);

        if( userp(obj) && environment(obj)->query("no_pk"))
		me->add("vendetta/pker",1);

	if (obj->query("race") != "元素" && me->query("race") != "元素")
		message_vision("\n$N对著$n喝道：「" 
		+ callname + "！今日不是你死就是我活！」\n\n", me, obj);
	else
		message_vision(HIR"\n$N大喝一声，开始对$n发动攻击！\n\n"NOR, me, obj);


	me->kill_ob(obj);
	if( !userp(obj) || !userp(me))
		obj->kill_ob(me);
	else {
		obj->fight_ob(me);
		tell_object(obj, HIR "如果你要和" + me->name() 
			+ "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
	}

	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	kill <人物>[0m
[0;1;37m────────────────────────────────[0m   

这个指令让你主动开始攻击一个人物，并且尝试杀死对方，kill 和 fight 
最大的不同在於双方将会真刀实枪地打斗，也就是说，会真的死伤。由於 
kill 只需单方面一厢情愿就可以成立，因此你对任何人使用 kill 指令都
会开始战斗，通常如果对方是 NPC 的话，他们也会同样对你使用 kill。

当有人对你使用 kill 指令时会出现红色的字样警告你，对於一个玩家而
言，如果你没有对一名敌人使用过 kill 指令，一般不会将对方真的打伤
或杀死。当然，刀枪无眼，偶尔也会有例外，所以如果是比武建议到雅人
处。

其他相关指令: fight

有关 fight 跟 kill 的区分请看 'help combat'.

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}
 
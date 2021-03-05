// command disabled by silencer. 3/6/2003
// Meaningless and can cause possible bugs.

#include <ansi.h>
inherit F_CLEAN_UP;

int legitimate_kill(object attacker, object victim);

int main(object me, string arg)
{
	object obj;
	string *killer, callname;
	object *t;
	int i;

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
	if (!legitimate_kill(me, obj)) {
		if (stringp(obj->query("NO_KILL")))
			return notify_fail(obj->query("NO_KILL"));
		if (stringp(obj->query("NO_PK")))
			return notify_fail(obj->query("NO_PK"));	
		else 
			return notify_fail("你无法攻击此人。\n");
	}
	
	if( userp(me) && userp(obj) && !environment(obj)->query("no_death_penalty"))
   	log_file( "KILL_LOG", sprintf("(%s)%s used kill on %s\n", 
   			ctime(time()), 
   			me->query("name")+"("+me->query("id")+")", 
   			obj->query("name")+"("+obj->query("id")+")"));
   			
	callname = RANK_D->query_rude(obj);
        t = me->query_team();
	if(sizeof(t) <=1)
		return notify_fail("你现在并没有参加任何队伍或队伍只你一个人。(use kill)\n");
	if( userp(obj) )
		return notify_fail("唉！你可不可以改掉以众欺寡的恶习？\n");

		
	for(i=0;i<sizeof(t);i++)
	if( t[i])
	if( environment(me) != environment(t[i]))
		return notify_fail("队员不都在场。(use kill)\n");		
	message_vision("\n$N对著$n喝道：「" + callname + "！今日不是你死就是我们活！」\n\n", me, obj);
        for(i=0;i<sizeof(t);i++)
	{
		if(t[i]){
			if (COMBAT_D->legitimate_kill(t[i], obj)) {;
				t[i]->set_temp("ttarget",obj->query("id"));
				t[i]->kill_ob(obj);
				obj->kill_ob(t[i]);
			}
		}
	}
	return 1;
}

// There is a similiar fuction in combatd.c
int legitimate_kill(object attacker, object victim) {
	if (userp(attacker) && (victim -> query("NO_KILL") || victim -> query("NO_PK")))
		return 0;
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : teamkill <人物>
 
这个指令让你的队伍主动攻击一个人物。
其他相关指令: team,fight,kill

HELP
    );
    return 1;
}
 

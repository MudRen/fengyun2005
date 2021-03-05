#include <ansi.h>
// shout.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !wizardp(me) )
		return notify_fail("目前暂不开放玩家 shout。\n");
	if (!arg) return notify_fail("你想要大叫什麽?\n");
	shout( HIW+me->name() + "纵声长啸：" + arg + "\n"NOR);
	write(HIW"你纵声长啸：" + arg + "\n"NOR);
	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	shout <讯息>[0m
[0;1;37m────────────────────────────────[0m   
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话.
 
see also : tune
[0;1;37m────────────────────────────────[0m   

HELP
    );
    return 1;
}
 

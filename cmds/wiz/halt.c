// halt.c

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !me->is_fighting() )
		return notify_fail("你现在并没有在战斗。\n");
	me->remove_all_killer();
	message_vision("$N用巫师的神力停止了这场打斗。\n", me);
	write("Ok.\n");
	return 1;
}

int help(object me)
{
   write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	halt[0m
[0;1;37m────────────────────────────────[0m   

停止所有与你有关的战斗。

[0;1;37m────────────────────────────────[0m   
HELP
   );
   return 1;
}

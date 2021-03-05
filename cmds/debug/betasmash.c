// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("指令格式: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("找不到这个生物。\n");
	if (userp(ob))
		return notify_fail("你不能对玩家使用此命令，请参看说明。\n");
	
	message_vision("$N手一挥，一道闪电从天而降，将$n化为齑粉！！\n",me,ob);
	ob -> die();
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	smash <生物>[0m
[0;1;37m────────────────────────────────[0m   

此命令将仅限于非玩家的生物，
对玩家处罚的命令可参见 nuke, exec, imprison, ban
 

[0;1;37m────────────────────────────────[0m   

HELP
   );
   return 1;
}

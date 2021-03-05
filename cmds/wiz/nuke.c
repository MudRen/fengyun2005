// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("指令格式: nuke <living>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("找不到这个玩家。\n");
	message_vision("$N双手一举，一个焦雷将$n劈为飞灰！！\n",me,ob);
	ob->set("kickout_time",time());
	ob -> save();
	seteuid(ROOT_UID);
	destruct(ob);
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	nuke <玩家>[0m
[0;1;37m────────────────────────────────[0m   
   
将某个玩家踢出风云，并且使其在一个小时内不可以联线。

相关命令	ban, imprison

[0;1;37m────────────────────────────────[0m   
HELP
   );
   return 1;
}

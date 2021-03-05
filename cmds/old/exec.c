// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("指令格式: exec <living>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("找不到这个玩家。\n");
	message_vision("$N双手一举，一个焦雷将$n劈为飞灰！！\n",me,ob);
	ob -> save();
        BAN_D->dynamic_add(query_ip_number(ob));
	seteuid(ROOT_UID);
	destruct(ob);
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	exec <玩家>[0m
[0;1;37m────────────────────────────────[0m   

将某个玩家踢出风云并将其IP暂时BAN掉
当风云重新REBOOT后，这个IP才可以再连线

相关指令 ban, nuke

[0;1;37m────────────────────────────────[0m 
HELP
   );
   return 1;
}

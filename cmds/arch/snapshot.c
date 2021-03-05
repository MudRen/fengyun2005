
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("指令格式: snapshot <living>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("找不到这个生物。\n");
	if (!userp(ob))
		return notify_fail("你不能对非玩家使用此命令，请参看说明。\n");
	"/feature/nada.c"->snapshot(ob);	
	write("Ok.\n");
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	snapshot <生物>[0m
[0;1;37m────────────────────────────────[0m   

此命令将给玩家的资料做一个“照相”，并登记在案。
读写命令，耗费资源。

[0;1;37m────────────────────────────────[0m   

HELP
   );
   return 1;
}

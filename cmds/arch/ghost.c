#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg || arg!="-p") {
		me->be_ghost(1);
		write("你成功地变成了一只鬼！\n");
	}
	else {
		me->be_ghost(0);
		write("你又投胎做人了！\n");
	}
	return 1;
}
		
int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	ghost [-p][0m
[0;1;37m────────────────────────────────[0m   
 
这个指令让你在人鬼之间切换！

[0;1;37m────────────────────────────────[0m 
HELP	);
	return 1;
}
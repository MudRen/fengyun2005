// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string msg;
	if(me->query_temp("proprop") && me->query_temp("block_msg/all")>=1)
	{
		me->add_temp("proprop",-1);
		me->add_temp("block_msg/all",-1);
		write(CLR);
		write("屏幕输入恢复正常状态，请继续工作：\n");
	} else
		write("你没有使用过BOSS指令。\n");
		
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: bossgone  

[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	指令格式: bossgone  [0m
[0;1;37m────────────────────────────────[0m   

这个指令让你(玩家)在老板走后恢复正常风云游戏。

有关指令：boss

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}

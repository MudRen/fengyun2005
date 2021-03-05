// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string msg;
	
	if (me->query_temp("proprop") || me->query_temp("block_msg/all"))
		return 1;
		
	write(CLR);	
	if(arg)
	{
		msg = read_file("/obj/nonsense.txt");
		write(msg);
	}
	me->add_temp("block_msg/all",1);
	me->add_temp("proprop",1);
	return 1;
}

int help(object me)
{
     write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	boss <arg>[0m
[0;1;37m────────────────────────────────[0m   

这个指令让你(玩家)在老板出现前一秒钟时将屏幕上
所有的中文消除，如果<arg>不是零的话，风云会在
你的屏幕上显示出一些文章。
与此同时，你将受不到任何来自风云的讯息，直到你
输入bossgone指令。

有关指令：bossgone

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}

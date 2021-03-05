#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_LEVEL;

int main(object me, string arg)
{
	int num;
	mapping data;
	
	if (!arg)
		return notify_fail("格式错误：请察看帮助文件。\n");

	if (sscanf(arg, "%d/%d", num) != 1)
		return notify_fail("格式错误：请察看帮助文件。\n");

	if ( num>0 && num <= 500)
	{
		write ("等级（"+num+"）	换算经验值（"+level_to_exp(num,0)+"）\n");
		return 1;
	}
	
	if ( num > 2000 && num < 100000000)
	{
		data = exp_to_level(num);
		
		write("经验值（" + num + "）换算：\n");
		write("	当前等级 = " + data["level"] + "\n");
		write("	该等级起始经验 = " + data["level_exp"] + "\n");
		write("	已完成百分数 = " + data["sub"] /10 + "." + data["sub"]%10 + "%\n");
		write("	这一等级共需要经验值 = " + data["next_level"] + "\n");
		
		return 1;
	}	
		
	return notify_fail("格式错误：请察看帮助文件。\n");
}
		
int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	exp_level [数字][0m
[0;1;37m────────────────────────────────[0m   
 
此命令让巫师检查经验与等级的换算，在命令后跟一个数字，

如果数字范围在0-500之间，将默认为是由等级换算经验，
如果数字范围2000-100000000之间，将默认为是由经验换算等级。

[0;1;37m────────────────────────────────[0m 
HELP	);
	return 1;
}
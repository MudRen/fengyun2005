// enhancesave.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int points, num;

	if( !arg ) 
	return notify_fail("你现已存入了"+(string)(me->query("enhance/pot_save"))+"点潜能。\n");
	
	points = me->query("potential") - me->query("learned_points");
	
	if (sscanf(arg,"%d",num)!=1)
		return notify_fail("Enhancesave <潜能数目>\n");
		
	if( num<0 )
		return notify_fail("输入的潜能必须是正数。\n");
	
	if( points < num )
		return notify_fail("你现有的潜能少于你输入的数目。\n");

	if(me->is_busy())
		return notify_fail("你上个动作还没完成。\n");

	me->add("enhance/pot_save", num);
	me->add("potential",-num);
	write("你成功地存入了" + (string)(num)+ "点潜能！\n");
	me->start_busy(1);
	return 1;
}

int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	enhancesave <潜能值>[0m
[0;1;37m────────────────────────────────[0m   

这个指令可以让你将潜能存储起来用于以后的Enhance。
存储后的潜能将不能再返回，只能用于Enhance。
使用无参数的Enhancesave可察看当前已存储的潜能值。

[0;1;37m────────────────────────────────[0m  

HELP
        );
        return 1;
}

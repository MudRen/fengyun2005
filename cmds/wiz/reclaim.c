// reclaim.c

int main(object me, string arg)
{
	int mem;

	write("整理结果，共清除 " + reclaim_objects() + " 个变数。\n");
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	reclaim[0m
[0;1;37m────────────────────────────────[0m   

用处 : 将存在於记忆体里无用的变数清除掉, 以减少记忆体的使用。

[0;1;37m────────────────────────────────[0m   
HELP
     );
     return 1;
}

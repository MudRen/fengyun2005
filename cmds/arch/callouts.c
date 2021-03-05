// callouts.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *info;
	int i;
	string output;

	output = sprintf("%-30s %-20s %5s \n", "物件", "函数", "延迟时间"); 
	if( arg && arg!="" )
		info = filter_array(call_out_info(), (: $1[1]==$2 :), arg);
	else
		info = call_out_info();

	for(i=0; i<sizeof(info); i++)
		output += sprintf("%-30O %-20s %5d \n",
			info[i][0], info[i][1], info[i][2] );

	me->start_more("", output, 0);
	return 1;
}

int help()
{
	write(@LONG
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	callouts [<函数名称>][0m
[0;1;37m────────────────────────────────[0m   

列出系统中所有的CALLOUTS

[0;1;37m────────────────────────────────[0m   
LONG
	);
	return 1;
}

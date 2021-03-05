// cost.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping before, after;
	int stime, usertime, eval_cost;

	if( me != this_player(1) ) me = this_player(1);

	seteuid(getuid());
   	if(!arg) 
   		return notify_fail("指令格式：cost <指令> [<参数> ....]\n");

    before = rusage();
	eval_cost = eval_cost();
	me->force_me(arg);
	eval_cost -= eval_cost();
	after = rusage();
	usertime = after["utime"] - before["utime"];
	stime = after["stime"] - before["stime"];
	printf("\n系统时间：%d 微秒\n使用者时间：%d 微秒\nEval cost：%d 单位\n",
		stime, usertime, eval_cost );
		
	return 1;

}

int help()
{
	write( @TEXT
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	cost <指令> [<参数> .... ][0m
[0;1;37m────────────────────────────────[0m   

这个指令让你测量另一个指令执行所需的时间。

[0;1;37m────────────────────────────────[0m   
TEXT
	);
	return 1 ;
}

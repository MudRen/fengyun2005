// time.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	write("现在是" + NATURE_D->game_time() + "。\n");
	return 1;
}

int help(object me)
{
     write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	time[0m
[0;1;37m────────────────────────────────[0m   

这个指令让你(玩家)知道现在的时辰。

[0;1;37m────────────────────────────────[0m
HELP
    );
    return 1;
}

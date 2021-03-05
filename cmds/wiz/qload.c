// qload.c

inherit F_CLEAN_UP;

int main()
{
    write(query_load_average() + "\n");
    return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	qload [0m
[0;1;37m────────────────────────────────[0m   

显示出目前 CPU 的负担, cmds/s 是每秒编译几个 cmds
comp lines/s 是每秒几行。

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}

// whoami.c

int main()
{
	write("你的 User ID = " + getuid(this_player()) + "\n" );
	write("你的 Effective User ID = " + geteuid(this_player()) + "\n" );
	return 1;
}

int help (object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	whoami[0m
[0;1;37m────────────────────────────────[0m   

显示出你的 User ID 及 Effective User ID 。

[0;1;37m────────────────────────────────[0m   
HELP
     );
    return 1;
}

// version.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string output;
//	write(__VERSION__+"\n");
	output = read_file("/doc/help/version.txt");
	write(output);
	return 1;
}
int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	version[0m
[0;1;37m────────────────────────────────[0m   

这个指令会显示游戏目前所用的MudOS以及MudLIB版本.

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}
 

// rehash.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg )
		return notify_fail("指令格式：rehash <路径>\n");

	if( arg[strlen(arg)-1]!='/' ) arg += "/";
	if(  file_size(arg)!=-2 )
		return notify_fail("没有这个目录！\n");

	write("更新指令表：" + arg + "\n");
	COMMAND_D->rehash(arg);
	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	rehash <目录名称>[0m
[0;1;37m────────────────────────────────[0m   

这个指令会更新系统内部的指令表，如果你新增或删除了某个目录下的
指令，必须用这个指令更新该目录才能使用。

[0;1;37m────────────────────────────────[0m   
HELP
	);
	return 1;
}

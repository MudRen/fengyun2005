// rmdir.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string dir;

	if(!arg) return help(me);

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));
	if( rmdir(dir) )
		write("Ok.\n");
	else
		write("删除失败。\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	rmdir <子目录名>[0m
[0;1;37m────────────────────────────────[0m   

指令格式 : rmdir <子目录名>

删除一个空的子目录。

[0;1;37m────────────────────────────────[0m 
HELP
	);
	return 1;
}

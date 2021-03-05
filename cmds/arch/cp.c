// cp.c
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	string src, dst, *dirs;
 
	seteuid(geteuid(me));
	if (!arg || sscanf(arg, "%s %s", src, dst)!=2 ) return
		notify_fail("指令格式: cp <原档名> <目标档名> \n");

	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);

	if( file_size(dst)==-2 ) {
		dirs = explode(src, "/");
		dst += "/" + dirs[sizeof(dirs)-1];
	}

	if( cp(src, dst) )
		write("Ok.\n");
	else
		write("你没有足够的读写权利。\n");
	return 1;
}
 
int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	cp <原档名> <目标档名>[0m
[0;1;37m────────────────────────────────[0m   

此指令可让你拷贝档案。

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}
 

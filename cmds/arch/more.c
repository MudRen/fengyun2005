// cat.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;
	object ob;

	seteuid(geteuid(me));
	if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file) < 0 ) {
		ob = present(arg, me);
		if( !ob ) ob = present(arg, environment(me));
		if( !ob ) return notify_fail("没有这个档案。\n");
		file = base_name(ob) + ".c";
	}
	me->start_more("", read_file(file), 0);
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	more <档案>|<物件名>[0m
[0;1;37m────────────────────────────────[0m   

分页显示档案内容。
 
more 模式下的指令:
q      : 离开 more.
b      : 显示前一页的内容.
[ENTER]: 显示下一页的内容.

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}

// edit.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
	if( !file ) return notify_fail("指令格式：edit <档名>\n");

	if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");

	seteuid(geteuid(me));
	ed(resolve_path(me->query("cwd"), file));
	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	edit <档名>, edit here[0m
[0;1;37m────────────────────────────────[0m   

指令格式 : edit <档名>, edit here

利用此一指令可直接在线上编辑档案。
[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}

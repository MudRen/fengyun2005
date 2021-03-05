// purge.c

#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string file;
	string *tmp;
	int loop;
        if(!me->query("env/yesiknow")) return notify_fail("这个指令已经被废除了！\n");
	file = read_file(arg);
	tmp = explode(file,"\n");
	for(loop=0; loop<sizeof(tmp); loop++)
	{
	reset_eval_cost();
	"/cmds/wiz/update"->main(me,"/"+tmp[loop]);
	}
	write("DONE\n");
	return 1;
}

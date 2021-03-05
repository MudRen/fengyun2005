#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string target, cmds;
	object obj;	

        if(!arg || sscanf(arg, "%s to %s", target, cmds)!=2 )
                return notify_fail("指令格式：order <对象> to 〈命令>\n");

        if( !(obj = present(target, environment(me))) || !obj->is_character())
                return notify_fail("你要向谁下命令？\n");

        if( !living(obj) )
                return notify_fail("嗯....你得先把" + obj->name() +
"弄醒再说。\n");
	
	if (obj->query("acc_cmd")!=me)
		return notify_fail("对方好象不会听从你的命令的样子。\n");

	obj->ccommand(cmds);
	return 1;
}

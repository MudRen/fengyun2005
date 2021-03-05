// File : /cmds/arch/cpstat.c
// annie 07.04.2003 dancing_faery@hotmail.com

#include <dbase.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_ANNIE;

int help(object me);

int main(object me, string arg)
{
	string tmp1,tmp2;
    	object ob, ob1;


	seteuid(geteuid(me));

	if (!arg)
		return notify_fail ("\n[USAGE]\n　　cpskill <source> <destination>\n");
    
    	sscanf (arg, "%s %s", tmp1,tmp2);

	if (!tmp1 || !tmp2)
		return notify_fail ("\n[USAGE]\n　　cpskill <source> <destination>\n");
	
    	ob=present(tmp1, environment(me));
    	ob1=present(tmp2, environment(me));

	if (!ob || !ob1)
		return notify_fail ("\n[USAGE]\n　　cpskill <source> <destination>\n");

	if (!ob->is_character())
		if (!ob1->is_character())
			return notify_fail ("Cpstat：本指令的复制源与目标源必须是生物。");
	
	tell_object(me,annie_skillcp(ob,ob1));
    	return 1;
}


int help(object me)
{
    write( @HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : cpskill ][0m
[0;1;37m────────────────────────────────[0m

指令说明: 该指令用来复制对象身上的所有技能

[0;1;37m────────────────────────────────[0m
HELP
        );
    return 1;
}
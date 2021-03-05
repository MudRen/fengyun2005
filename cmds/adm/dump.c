// dump.c (should be admin cmd?)

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	seteuid(geteuid(me));

    dumpallobj();

	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	dump[0m
[0;1;37m────────────────────────────────[0m   

dump the stats of all objects to a file in root dir 
named OBJ_DUMP.

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}
 

// pwd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ) {
		write("Cwd: " + (string)me->query("cwd") +  "\n");
		write("Cwf: " + (string)me->query("cwf") +  "\n");
		return 1;
	}
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	pwd[0m
[0;1;37m────────────────────────────────[0m   

这个指令会显示出你目前的工作目录 (cwd) 及工作档案 (cwf).
'update' 不加参数时便会更新你的 cwf.

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}

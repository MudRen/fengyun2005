// unset.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	if( !arg || arg=="" ) return help();

	me->delete("env/" + arg);
	write("Ok.\n");
	return 1;
}

int help()
{
	write(@TEXT
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	unset <变数名>[0m
[0;1;37m────────────────────────────────[0m   

这个指令让你删除环境变数的设定。
修改变数设定请用 set 指令。

至於有哪些环境变数可以设定，请见 help settings.txt。

[0;1;37m────────────────────────────────[0m 

TEXT
	);
	return 1;
}

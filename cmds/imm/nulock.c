// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(wizard)") )
		return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
	if( !arg || arg=="" )
		return notify_fail("指令格式：nulock <0/1>\n");

	if( sscanf(arg, "%d", lvl)!=1 )
		return notify_fail("指令格式：nulock <0/1>\n");
	seteuid(getuid());
	if( LOGIN_D->set_newuser_lock(lvl) ) {
		write("风云开始不接受新人物！\n");
		return 1;
	} else
		return notify_fail("风云开始接受新人物。\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	nulock <0/1>[0m
[0;1;37m────────────────────────────────[0m    

限制风云是否接受新人物．

[0;1;37m────────────────────────────────[0m  
HELP
);
        return 1;
}
 

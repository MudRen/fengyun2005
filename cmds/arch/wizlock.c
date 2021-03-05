// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
	if( !arg || arg=="" )
		return notify_fail("指令格式：wizlock <巫师等级>\n");

	if( sscanf(arg, "%d", lvl)!=1 ) lvl = wiz_level(arg);
	seteuid(getuid());
	if( LOGIN_D->set_wizlock(lvl) ) {
		write(sprintf("\n进入游戏等级限制在%s\n",chinese_number(lvl)));
		return 1;
	} else
		return notify_fail("上线权限设定失败。\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	wizlock <巫师等级>[0m
[0;1;37m────────────────────────────────[0m   

限制某个等级以下的使用者进入游戏。
其中巫师等级分别为 (immortal) (wizard) (arch) (admin), 若要取
消限制, 则输入 (player).

[0;1;37m────────────────────────────────[0m  
HELP
);
        return 1;
}
 

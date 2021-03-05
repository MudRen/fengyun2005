// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
	
	if( !arg || arg=="" ) {
		return notify_fail("当前风云可登陆的最大人数为："+ LOGIN_D->query_max_users()+" \n");	
	}
	
	if( sscanf(arg, "%d", lvl)!=1 ) 
		return notify_fail("参见HELP格式说明。\n");
		
	seteuid(getuid());
	
	if (lvl>0 && lvl<10) {
		LOGIN_D->set_dummy_number(lvl-1);
		write(sprintf("\n当前每个ip可以连线人数设置为%d\n", lvl));
		return 1;
	}
		
	if( LOGIN_D->set_max_users(lvl)) {
		write(sprintf("\n进入游戏人数设置为%d	\n",lvl));
		return 1;
	} else
		return notify_fail("上线人数设定失败。\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	loginlock <数字>[0m
[0;1;37m────────────────────────────────[0m   

此命令有两个作用

（1）当数字<10时，可设定当前游戏中每个ip可以登陆的人数（游戏默认为3）

loginlock 1	意思就是每个ip只能为一个人

（2）限制共有多少使用者可以进入游戏。
每次重启（或重载logind）后缺省登陆人数为２００，此指令可动态设置

loginlock 300		允许同时登陆人数为300

注：如果你要给某个ip多一些登陆人数的话，使用netbar命令

目前netbar能做的是
（1）整个游戏取消ip-id限制
（2）给某个ip加倍login人数

[0;1;37m────────────────────────────────[0m  
HELP
);
        return 1;
}
 

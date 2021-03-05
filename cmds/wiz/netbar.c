// netbar.c

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
		NETBAR_D->print();
	else if (arg == "-s") {
		NETBAR_D->netbar_switch();	
	}	
	else if (sscanf(arg, "-y + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能使用以 *, +, ? 结尾的地址。\n");
		else
			NETBAR_D->add(site);
	}
	else if (sscanf(arg, "-y - %s", site) == 1) {
		NETBAR_D->delete(site);
	}
	else if (sscanf(arg, "-n + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能使用以 *, +, ? 结尾的地址。\n");
		else
			NETBAR_D->add_ban(site);
	}
	else if (sscanf(arg, "-n - %s", site) == 1) {
		NETBAR_D->delete_ban(site);
	}
	else if (sscanf(arg, "-a + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能使用以 *, +, ? 结尾的地址。\n");
		else
			NETBAR_D->add_all(site);
	}
	else if (sscanf(arg, "-a - %s", site) == 1) {
		NETBAR_D->delete_all(site);
	}	
		
	else 
		write("请参看指令格式	netbar -参数 [+|- site]\n");

	return 1;
	
}

int help()
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 :		netbar -参数 [+|- site] [0m
[0;1;37m────────────────────────────────[0m   

风云2005缺省设置为每个ip登陆三个账号。
这条命令是用来具体调节每个ip的登陆人数

使用说明

netbar		输出列表

netbar -s	开关参数，用来控制是否限制ip的登陆人数

netbar -y	+ xx.xx.xx.xx
netbar -y	- xx.xx.xx.xx
			将某个ip或ip段加入/消除netbar，该ip可以有加倍的登陆线

netbar -n	+ xx.xx.xx.xx
netbar -n	- xx.xx.xx.xx
			将某个ip或ip段加入/消除netbarn，该ip将没有加倍的登陆线

为什么有netbar和netbarn两种呢，netbarn是用来处理一种罕见的
情况，比如说，你想让128.22.22.*有加倍的登陆，但又不想让
128.22.22.3有加倍的登陆，那么就应该同时使用两个命令
netbar -n + 128.22.22.3
netbar -y + 128.22.22


netbar -a + xx.xx.xx.xx		该ip无登陆人数限制
netbar -a - xx.xx.xx.xx		恢复到正常状态
注意，此命令必须是完整的ip才有效。


有关命令：loginlock 可改变每个ip的登陆人数

[0;1;37m────────────────────────────────[0m 
HELP
	);
	return 1;
}
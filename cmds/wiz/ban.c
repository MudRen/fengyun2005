// ban.c

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
		BAN_D->print();
	else if (sscanf(arg, "+ %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能禁以 *, +, ? 结尾的地址。\n");
		else
			BAN_D->add(site);
		}
	else if (sscanf(arg, "- %s", site) == 1)
		BAN_D->delete(site);
	else if (sscanf(arg, "-a + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("不能加入以 *, +, ? 结尾的地址。\n");
		else
			BAN_D->add_allow(site);	
	}
	else if (sscanf(arg, "-a - %s", site) == 1)
		BAN_D->delete_allow(site);
	else 
		write("指令格式：ban -参数 [+|- site]\n");

	return 1;

}

int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 :		ban [-a] [+|-] site [0m
[0;1;37m────────────────────────────────[0m   

这条命令是用来防止有人蓄意捣乱。

+	是禁止别人访问
-	是删除ban掉的地址
-a	是加入允许进入的地址

比如你可以 ban + 211.100，然后ban -a + 211.100.99.11
这样就ban掉了整个211.100网段，但是允许211.100.99.11这个ip进入

可以采用?和*等通配符

相关命令	nuke
		
[0;1;37m────────────────────────────────[0m   

HELP
	);
	return 1;
}

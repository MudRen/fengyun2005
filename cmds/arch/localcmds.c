// localcmds.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *cmds;
	int i;
    
#ifdef	ENCRYPTED_WRITE	
		return notify_fail("该命令只有在ｄｅｖ站点才需要运行。\n");
#endif      
       
    if(!me->query("env/yesiknow")) return notify_fail("这个指令已经被废除了！\n");
		
	cmds = me->query_commands();
	write("你身上及四周的物品与所在的环境提供以下指令：\n");
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		printf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]);
	}
	return 1;
}

int help()
{
	write(@TEXT
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	localcmds[0m
[0;1;37m────────────────────────────────[0m   

列出你身上及四周的物品与所在的环境提供的所有指令。

[0;1;37m────────────────────────────────[0m   
TEXT
	);
	return 1;
}


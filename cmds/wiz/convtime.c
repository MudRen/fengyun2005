inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int time;
        if(!arg || sscanf(arg,"%d",time)!=1)
        	return notify_fail("USAGE:convtime time.\n");
        write(sprintf("您输入的为：%d，对应时间为：%s\n",time,ctime(time)));
        return 1;
}

int help(object me)
{
     write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	convtime [0m
[0;1;37m────────────────────────────────[0m   

这个指令将mud_time转化为正常的时间显示。

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}

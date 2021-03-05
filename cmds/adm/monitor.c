#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;
        int num;
        string name;

        if(!arg)
        	return notify_fail("请用help查看此指令用法！\n");
        
        if(sscanf(arg,"%s %d", name,num)!=2)
        	return notify_fail("请用help查看此指令用法！\n");
                
        ob=find_player(name);
        if(!ob)
			return notify_fail("此指令只能对在线玩家使用。\n");

		if (num>5 || num<0)
			return notify_fail("请用help查看此指令用法！\n");
			
        ob->set("MONITORING", num);
		if (!num)
			ob->delete("MONITORING");
		
		write(sprintf("开始对%s(%s)进行%d级纪录。\n", ob->name(1),ob->query("id"),num));
		return 1;
		        
}


int help(object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	monitor ID 0/1/2/5 [0m
[0;1;37m────────────────────────────────[0m   

使用这个指令对某ID的行为作记录，该指令目的是追踪一些不明行为，
耗费系统资源（机时、硬盘空间），既不要轻易使用，也不要长期使用。
纪录文件在/log/backup/内

monitor xxx 0	停止对某ID的纪录
monitor xxx 1	对该ID增加combat_exp/potential/saved_quest
		的操作加以记录
monitor xxx 2	对该ID增加交谈纪录
monitor xxx 3	(undecided)
monitor xxx 4	(undecided)
monitor xxx 5   对该ID所有非行走的行为加以记录（足够硬盘？）

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}

// Silencer@fengyun workgroup	June.2005

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string output;
	object *ob;
	int i;
	
	seteuid(getuid());
	
	if (arg == "-refresh"){
		ob = users();	
		for (i=0;i<sizeof(ob);i++) {
			if (!ob[i] || !objectp(ob[i])) continue;
			if (!(i%10))
				reset_eval_cost();
			STATUS_D->compare_status(ob[i]);
		}
		write("共计"+ sizeof(ob)+"个对象，更新完毕。\n");
		return 1;
	}
		
	if (arg == "-rich")
	{
		output = STATUS_D->show_rich();
		me->start_more("", output, 0);		
	}	
	else if (arg == "-riddle")
	{
		output = STATUS_D->show_riddle();
		me->start_more("", output, 0);		
	}
	else {
		output = STATUS_D->show_top();
        me->start_more("", output, 0);
    }
    return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	showtop [<参数> .... ][0m
[0;1;37m────────────────────────────────[0m  
这个指令显示出TOP玩家的进程速度。

showtop 		显示top15 经验值的玩家
showtop -riddle:	显示top15 解密的玩家
showtop -rich:	显示top15 存款的玩家

showtop -refresh 强制系统更新当前在线玩家的纪录（耗费资源）

注：该数据来源于登陆和退出时的纪录。

[0;1;37m────────────────────────────────[0m
HELP
    );
    return 1;
}

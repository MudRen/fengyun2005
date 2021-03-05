// Silencer@fengyun workgroup	June.2005

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string output;
	object *ob;
	int i;
	
	ob = users();	
	for (i=0;i<sizeof(ob);i++) {
		if (!ob[i] || !objectp(ob[i])) continue;
		if (!(i%10))
			reset_eval_cost();
		ob[i]->ccommand("qsave");
	}
	write("共计"+ sizeof(ob)+"个对象，更新完毕。\n");
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	qbox_save[0m
[0;1;37m────────────────────────────────[0m  

这个指令将令所有玩家执行ｑｓａｖｅ命令，把玄灵玉盒交还给鹦鹉阁。

[0;1;37m────────────────────────────────[0m
HELP
    );
    return 1;
}

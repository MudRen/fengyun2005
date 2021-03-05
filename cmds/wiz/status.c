// status.c

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string msg;

	msg = (string)mud_status(arg=="detail" ? 1 : 0);
	if( stringp(msg) ) write(msg);

	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	status [detail][0m
[0;1;37m────────────────────────────────[0m   

这个指令可以显示出目前游戏的一些相关资料及状况.

[0;1;37m────────────────────────────────[0m  
HELP
    );
    return 1;
}
 

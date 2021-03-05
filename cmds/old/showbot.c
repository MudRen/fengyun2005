// TIE@fy3

inherit F_CLEAN_UP;
int main(object me)
{
	string output;
	output = STATUS_D->show_bot();
        me->start_more("", output, 0);
    return 1;
}

int help(object me)
{
write(@HELP
指令格式 : showbot

这个指令显示出目前玩家的进程速度，从这里可以看出一些玩家的DUMMY.
HELP
    );
    return 1;
}

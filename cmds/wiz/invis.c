#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg || arg!="-p") {
		me->set("wiz_invis",1);
		me->set("env/msg_mout","none");
		me->set("env/msg_min","none");
		me->set("env/invisibility",1);
		me->be_ghost(1);
		write("隐身成功。\n");
	}
	else {
		me->delete("wiz_invis");
		me->delete("env/invisibility");
		me->delete("env/msg_mout");
		me->delete("env/msg_min");
		me->be_ghost(0);
		write("取消隐身！\n");
	}
	return 1;
}
		
int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	invis [-p][0m
[0;1;37m────────────────────────────────[0m   
 
这个指令让你进入隐身模式：
（1）玩家无法用Finger或Who来检测你的在线情况。
（2）Goto或Go命令将不再向所在房间显示信息。

[0;1;37m────────────────────────────────[0m 
HELP	);
	return 1;
}
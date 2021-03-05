// emote.c (Mon  09-04-95)

#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string str)
{
    	if (!str) {
        	write(CYN"你看起来表情丰富。\n"NOR);
        	tell_room(environment(me), CYN+(string)me->name()+
			"看起来表情丰富。\n" +NOR, me);
        	return 1;
    	}
    	write(CYN"你"+str+"\n"NOR);
    	tell_room(environment(me), CYN+(wizardp(me)? "":"  ")+(string)me->name()+
        str+"\n"+NOR, me);
    	return 1;
}
 
int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	emote <动作词>[0m
[0;1;37m────────────────────────────────[0m   

这个指令可以让你表达一个系统没有预设的动作词, 系统会将你所输入
的文字加上你的姓名後显示给所有在同一个地方的生物看. 为了避免造
成困扰, 玩家所输入的词句前面会加上 -> 以供区别. (管理则不在此
限.)

□例: emote 坐了下来。
你会看见: 你坐了下来。
其他人会看到: ->包子坐了下来。

其中, 包子就是你的名字.

相关指令: semote
[0;1;37m────────────────────────────────[0m   
HELP
	);
        return 1;
}

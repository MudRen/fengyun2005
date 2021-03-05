// home.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;

//	if( file_size(user_path(geteuid(me)) + "workroom.c") <= 0 )
//		return notify_fail("你没有自己的工作室。\n");

	if( stringp(msg = me->query("env/msg_home")) )
		message_vision(msg + "\n", me);
//	me->move(user_path(geteuid(me)) + "workroom");
        me->move("d/wiz/jobroom"); 
        	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	home[0m
[0;1;37m────────────────────────────────[0m   

利用此一指令可直接回到自己的工作室。
如果你有 'msg_home' 这个设定, 则在场的人都会看到那个讯息。

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}

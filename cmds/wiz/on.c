// channel block command..
// Modified by Marz, 04/18/96

#include <globals.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
    if (!arg)
	{
	if(CHANNEL_D->query("block_chat"))
		write("chat	off\n");
	else    write("chat	on\n");
        if(CHANNEL_D->query("block_rumor"))
                write("rumor	off\n");
        else    write("rumor	on\n");
        if(CHANNEL_D->query("block_fy"))
                write("fy	off\n");
        else    write("fy	on\n");
        if(CHANNEL_D->query("block_new"))
                write("new	off\n");
        else    write("new	on\n");

	return 1;

	}
   if( arg == "rumor" || arg == "chat" || arg == "fy" || arg == "new")
	{
	CHANNEL_D->set_block(arg,0);
	EMOTE_D->set_block(arg,0);
	}
	else
	return notify_fail(" channel_name 只可以是 rumor, chat, fy,和new中的一个。\n"); 

	tell_object(me, arg+"频道被开启了。\n");
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	on <频道> [0m
[0;1;37m────────────────────────────────[0m   

此命令将开启某个频道，频道可以是 rumor, chat, fy,和new中的一个。

相关命令 off

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}

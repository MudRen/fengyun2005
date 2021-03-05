// channel block command..
// Modified by Marz, 04/18/96

#include <globals.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name;
	
    if (!arg)
        return notify_fail("指令格式：chblk name \n");
    
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("这个人不在！\n");
	if (wizardp(ob)) return notify_fail("不能关闭巫师的频道。\n");
	ob->set("chblk_on",1);	
	tell_object(me, (string)ob->query("name")+"的频道被关闭了。\n");
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	chblk <某人> [0m
[0;1;37m────────────────────────────────[0m   

此命令将关闭某人的所有频道，
包括ｃｈａｔ，ｒｕｍｏｒ，ｎｅｗ，ｆｙ，和ｔｅｌｌ

相关命令 unchblk

[0;1;37m────────────────────────────────[0m    
HELP
    );
    return 1;
}

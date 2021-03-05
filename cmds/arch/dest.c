// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string option, target, msg;

	object obj;

	if (!arg) return notify_fail("指令格式 : dest <物件之名称或档名>\n" );

	if( sscanf(arg, "-%s %s", option, target)!=2 ) target = arg;

	if( option == "-r" && (string)SECURITY_D->get_status(me)=="(admin)" )
		seteuid(ROOT_UID);
	else
		seteuid(geteuid(me));

	obj = find_object(target);
	if (!obj) obj = present(target, me);
	if (!obj) obj = present(target, environment(me));
	if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
	
	if (!objectp(obj)) 
		return notify_fail("没有这样物件....。\n");

	if ( userp(obj) &&  (string)SECURITY_D->get_status(me)!="(admin)" )
		return notify_fail("你没有摧毁对方的权限。\n");
	
	tell_object( me, sprintf("摧毁物件： %O\n", obj));
	
	msg = "";
	
	if( environment(me)==environment(obj) )
	{
		if( !stringp(msg = me->query("env/msg_dest")) )
			msg = "$N召唤出一个黑洞，将$n吞没了。\n";
		message_vision(msg + "\n", me, obj);
	}
	else {
		msg = "$N召唤出一个黑洞，把周围吞没了。\n";
		message_vision(msg + "\n", me);
	}
	
	destruct(obj);
	if(obj) 
		write("你无法将这个物件摧毁。\n");
	else 
		write("物件摧毁成功。\n");

	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	dest [-r] <物件之名称或档名>[0m
[0;1;37m────────────────────────────────[0m   

利用此一指令可将一个物件(object)或物件定义(class)从记忆体中清除，
若清除物件定义(即：指定档名的情况下)则下一次参考到这个物件的时候
会重新将它编译。

具有 (admin) 身分的巫师可以用 -r 选项以 ROOT_UID 身分来清除被保
护的物件如使用者。

参考资料： destruct()

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}

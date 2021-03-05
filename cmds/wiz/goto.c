// goto.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int goto_inventory = 0;
	object obj/*,obj1*/;
	string msg;

	if( !arg ) return notify_fail("你要去哪里？\n");

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

	if (wiz_level(me)<4 && goto_inventory)
		return notify_fail("你的管理权限无法进入物体内部。\n");
			
	if( !arg ) return notify_fail("你要去哪里？\n");

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("没有这个玩家、生物、或地方。\n");
		}
	}
	
	if (wiz_level(me)<4 && !environment(obj) && obj->query("id"))
		return notify_fail("你的管理权限无法进入此物体内部。。\n"); 
		
	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("这个物件没有环境可以 goto。\n");
	
	if( stringp(msg = me->query("env/msg_mout")) ) {
	        if (msg!="none") message_vision(msg+"\n",me);		
	} else	{
			message("vision","你眼前一花，"+me->name()+"的身影已经不见了。\n",environment(me),me);
			if (environment(me)->query("name"))
				tell_object(me,"你离开了"+environment(me)->query("name")+"。\n");
			else tell_object(me,"你离开了"+environment(me)->query("short")+"。\n");
	}
						
	if(me->move(obj)) {
		if ( obj->name(1))
		/*log_file("static/GOTO_LOG",
			sprintf("%s(%s) goto -i %s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj),
				ctime(time()) ) );*/
		
		if( stringp(msg = me->query("env/msg_min")) ) {
	        	if (msg!="none") message_vision(msg+"\n",me);
		} else	{
			message("vision","你眼前一花，"+me->name()+"的身影出现在面前。\n",environment(me),me);
			if (goto_inventory || !environment(me)->query("short")) tell_object(me,YEL"你身影一闪，来到了"+obj->name()+NOR+YEL"的体内。\n"NOR);
				else tell_object(me,YEL"你身影一闪，来到了"+environment(me)->query("short")+"。\n"NOR, me);	
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	goto [-i] <目标>[0m
[0;1;37m────────────────────────────────[0m   
 
这个指令会将你传送到指定的目标. 目标可以是一个living 或房间
的档名. 如果目标是living , 你会被移到跟那个人同样的环境.
如果有加上 -i 参数且目标是 living, 则你会被移到该 living 的
的 inventory 中.

set msg_min/msg_mout <描述> 可供你自己选择进入/离开房间的描述。
set msg_min/msg_mout none 将不显示进入/离开房间的信息。

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}
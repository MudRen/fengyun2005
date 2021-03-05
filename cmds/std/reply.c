// reply.c

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
    string target, mud;
    object obj;
    string refuse_name,filename;

    if( !arg || arg=="" )
	return notify_fail("你要回答什麽？\n");
    if(me->query("chblk_on"))
	return notify_fail("你的频道被关了！\n");
    if( !stringp(target = me->query_temp("reply")) )
	return notify_fail("刚才没有人和你说过话。\n");

    if( sscanf(target, "%s@%s", target, mud)==2 ) {
	GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
	write("网路讯息已送出，可能要稍候才能得到回应。\n");
	return 1;
    }

    obj = find_player(target);
    if( !obj )
	return notify_fail("刚才和你说话的人现在无法听见你，或者已经离开游戏了。\n");
    if(obj->query_temp("is_unconcious")) return notify_fail("他/她现在无法听到你说的话。\n");
    if(obj->query_temp("block_msg/all")) return notify_fail("他/她现在无法听到你说的话。\n");

    refuse_name = (string) obj->query("env/no_tell");
    if( !wizardp(me) && (refuse_name == "all" || refuse_name == (string) me->query("id")))
	return notify_fail("此人已关闭了ＴＥＬＬ频道。\n");
    write(YEL "你回答" + obj->name(1) + "：" + arg + "\n" NOR);
    tell_object(obj, sprintf(YEL"%s回答你：%s\n"NOR,
	me->name(1), arg ));

	// MONITORING
	if (obj->query("MONITORING")>=2){
		filename = getuid(obj);
		log_file("backup/" + filename, sprintf(
				"%s %s at %s 回答 %s --- %s\n",
				me->query("id"), me->query("name"),
				ctime(time()),
				filename, 
				arg) );
	}
	
	if (me->query("MONITORING")>=2){
		filename = getuid(me);
		log_file("backup/" + filename, sprintf(
				"%s %s at %s 回答 %s --- %s\n",
				me->query("id"), me->query("name"),
				ctime(time()),
				obj->query("id"), 
				arg) );
	}
	// END MONITORING

    obj->set_temp("reply", me->query("id"));
    return 1;
}

int help(object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	reply <讯息>[0m
[0;1;37m────────────────────────────────[0m   
指令格式：reply <讯息>

你可以用这个指令和刚才用 tell 和你说话的使用者说话。

see also : tell

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}

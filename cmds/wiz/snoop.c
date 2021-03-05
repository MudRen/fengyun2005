// snoop.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, ob1;

	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("你现在正在监听" + ob->query("name") + "所收到的讯息。\n");
		else
			write("你现在不在监听任何信息。\n");	
		return 1;
	} else if( arg=="none" ) {
		if( objectp(ob = query_snooping(me))
		&&	wiz_level(ob) >= wiz_level(me) )
			tell_object(ob, HIW + me->name(1) + "停止监听你所收到的讯息。\n" NOR);
		snoop(me);
		if (objectp(ob))
			write("你现在停止监听" + ob->query("name") + "所收到的讯息。\n");
		else
			write("你现在不在监听任何信息。\n");
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");

	if( wizhood(me) != "(admin)"
	&&	wiz_level(me) <= wiz_level(ob) )
		return notify_fail("你没有监听" + ob->name() + "所收听讯息的权利。\n");

	if( me==ob ) return notify_fail("请用 snoop none 解除监听。\n");
	
	if (objectp(ob1=query_snoop(ob)))
		return notify_fail(ob1->name()+"正在监听"+ob->name()+"的信息。\n");
	
	if (ob->query_temp("netdead",1))
		return notify_fail("此人正处在断线状态。\n");
	
	if (!userp(ob))
		return notify_fail("没法窃听NPC信息的。\n");
				
	snoop(me, ob);
	write("你现在开始窃听" + ob->name(1) + "所收到的讯息。\n");
	if( userp(ob) ) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );
	if( wizardp(ob) && wizhood(me) != "(admin)")
		tell_object(ob, HIW + me->name(1) + "开始监听你所收到的讯息。\n" + NOR);

	return 1;
}

int help()
{
	write(@TEXT
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	snoop <某人>|none[0m
[0;1;37m────────────────────────────────[0m   

监听其他使用者所收听的讯息，snoop none 则取消监听。

[0;1;37m────────────────────────────────[0m   
TEXT
	);
	return 1;
}

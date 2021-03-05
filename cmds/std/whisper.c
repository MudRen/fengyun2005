// whisper.c

#include <ansi.h>
#define NEW_PERIOD 32400
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg;
	object ob;
	
	if((int)me->query("mud_age") < NEW_PERIOD)
		return notify_fail("你只可以使用（say）。\n");
	
	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("你要对谁耳语些什麽？\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("你要对谁耳语？\n");

	write( GRN "你在" + ob->name() + "的耳边悄声说道：" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "在" + ob->name()
		+ "耳边小声地说了些话。\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + me->name() + "在你的耳边悄声说道：" + msg + "\n" NOR);
	return 1;
}

int help(object me)
{
	write( @TEXT
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	whisper <某人> <讯息>[0m
[0;1;37m────────────────────────────────[0m   

这个指令可以用来和同一房间中的人耳语，包括 NPC 在内。

[0;1;37m────────────────────────────────[0m   
TEXT
	);
	return 1;
}

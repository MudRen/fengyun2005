#define SCORE_COST 5000
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    object who;
    if( !arg ) return notify_fail("指令格式 : assign <id>\n");
    if(me->query("organization/privs") != -1) 
	return notify_fail("你没有这种权力。\n");
    if(!objectp(who = present(arg, environment(me))) 
       || !living(who) || !userp(who) || me == who)
        return notify_fail("这里没有这个玩家。\n");
    if(who->query("organization/org_name") != me->query("organization/org_name"))
	return notify_fail( who->query("name") + "并不是" + 
                            me->query("organization/org_name") + "的一份子。\n");
    if((int)me->query("organization/generation") >=
       (int)who->query("organization/generation"))
	return notify_fail(who->query("name") +
                           "的辈份必须比你低！\n");
    if((int)who->query("score") < SCORE_COST)
	return notify_fail( who->query("name") + "的评价不够"+
                            chinese_number(SCORE_COST)+"点。\n");
    who->set("organization/privs",-1);
	who->delete("organization/org_title");
    me->set("organization/privs",1);
    who->add("score",-SCORE_COST);
    message_vision("$N将首领之位传给$n。\n",me,who);
    CHANNEL_D->do_sys_channel("info",sprintf(
        "%s(%s)将『%s』的首领之位传给了%s(%s)！",me->query("name"),
        me->query("id"),me->query("organization/org_name"),who->query("name"),who->query("id")));
    return 1;
}
int help(object me)
{
    write(@HELP
指令格式 : assign <id>
 
这个指令可以让你传让一帮之主的地位给另外的人物。
当然，这位玩家需要有一定的做帮主先提条件。
HELP
        );
    return 1;
}

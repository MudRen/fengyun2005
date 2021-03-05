// join.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object ob, old_join;
    mapping organization, skills;
    int i;
    string *skname;

    if( !arg ) return notify_fail("指令格式：join [cancel]|<对象>\n");

    if( arg=="cancel" ) {
        old_join = me->query_temp("pending/join");
        if( !objectp(old_join) )
            return notify_fail("你现在并没有加入任何组织的意思。\n");
        write("你改变主意不想拜" + old_join->name() + "的组织了。\n");
        tell_object(old_join, me->name() + "改变主意不想加入你的组织了。\n");
        me->delete_temp("pending/join");
        return 1;
    }

    if( !(ob = present(arg, environment(me)))
        || !ob->is_character() )
        return notify_fail("你想加入谁的组织？\n");

    if( mapp(me->query("organization")))
        if(me->query("organization/privs")==1)
            return notify_fail("你曾经是一组织之头，不能再加入别的组织了。\n");
        else if(me->query("organization/privs")==-1)
            return notify_fail("你是一组织之头，不能再加入别的组织了。\n");
    
    if( !living(ob) )
        return notify_fail("你必须先把" + ob->name() + "弄醒。\n");

    if( ob==me ) return notify_fail("自己加入自己？有骨气....不过没有用。\n");

    if( me->is_member_of(ob) ) {
        message_vision("$N恭恭敬敬地向$n拱手请安，叫道：「大哥！」\n", me, ob);
		if (!userp(ob)) ob->org_rerank(me);
        return 1;
    }

    if( !mapp( ob->query("organization") ) )
        return notify_fail(ob->name() +
                           "既不属於任何组织，也没有开创任何组织，不能加入。\n");
    if( userp(ob) && (int) ob->query("organization/privs") != -1 )
        return notify_fail("不是组织领袖不可吸收成员．\n");
    if((string)me->query("organization/org_name") ==
       (string)ob->query("organization/org_name"))
        if((int)me->query("organization/generation") <=
           (int)ob->query("organization/generation"))
            return notify_fail(ob->name()+"的辈分并不比你高！\n");
    // If the target is willing to recruit us already, we do it.
    if( (object)ob->query_temp("pending/enroll") == me )
    {
        if( (string)me->query("organization/org_name") !=
            (string)ob->query("organization/org_name"))
        {
            message_vision("$N决定背叛原来的组织，改投入$n的组织\n\n"
                "$N跪了下来向$n恭恭敬敬地磕了一个响头，叫道：「大哥！」\n\n",
                me, ob);
            if(me->query("score") > 5000) me->add("score", -5000);
            me->add("betrayer", 1);
        }
        else message_vision("$N决定加入$n组织。\n\n"
                "$N跪了下来向$n恭恭敬敬地磕了一个响头，叫道：「大哥！」\n\n",
                me, ob);

        ob->enroll_member(me);
        ob->delete_temp("pending/enroll");

        tell_object(ob, "恭喜你新收了一名成员！\n");
        organization = me->query("organization");
        printf("恭喜您成为%s的第%s代成员。\n", me->query("organization/org_name"),
               chinese_number( me->query("organization/generation")));

        return 1;
	
    } else {
        
        old_join = me->query_temp("pending/join");
        if( ob==old_join )
            return notify_fail("你想加入" + ob->name() +
                               "的组织，但是对方还没有答应。\n");
        else if( objectp(old_join) ) {
            write("你改变主意不想加入" + old_join->name() + "的组织了。\n");
            tell_object(old_join, me->name() + "改变主意不想加入你的组织了。\n");
        }

        message_vision("$N想要加入$n的组织。\n", me, ob);
        me->set_temp("pending/join", ob );
        if( userp(ob) ) {
            tell_object(ob, YEL "如果你愿意收" + me->name() +
                        "为成员，用 enroll 指令。\n" NOR);
        } else 
            ob->attempt_join(me);
	
        return 1;
    }
}

/*
int help(object me)
{
    write(@HELP
指令格式 : join [cancel]|<对象>
 
这个指令能让你拜某人为师，如果对方也答应要收你为徒的话，就会立即行
拜师之礼，否则要等到对方用 recruit 指令收你为弟子才能正式拜师。

请注意你已经有了师父，又背叛师门投入别人门下，所有技能可能会减半，并且
评价会降到零。

如果对你的师父使用这个指令，会变成向师父请安，并要求师父给你个
合适的称号。
 
请参考相关指令 expell、recruit
HELP
        );
    return 1;
}
*/
// enroll.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_enr;
	mapping organization;
	int i;

	if( !arg ) return notify_fail("指令格式：enroll [cancel]|<对象>\n");

	if( arg=="cancel" ) {
		old_enr = me->query_temp("pending/enroll");
		if( !objectp(old_enr) )
			return notify_fail("你现在并没有收录任何人为成员的意思。\n");
		write("你改变主意不想收" + old_enr->name() + "为成员了。\n");
		tell_object(old_enr, me->name() + "改变主意不想收你为成员了。\n");
		me->delete_temp("pending/enroll");
		return 1;
	}

	if( !(ob = present(arg, environment(me))) )
		return notify_fail("你想收谁作成员？\n");

	if( ob==me ) return notify_fail("收自己为成员？好主意....不过没有用。\n");

	if( ob->is_member_of(me) ) {
		message_vision("$N拍拍$n的头，说道：「好兄弟！」\n", me, ob);
		return 1;
	}

	if( !me->query("organization") )
		return notify_fail("你并不属於任何组织，你必须先加入一个组织，或自己创一个才能吸收成员。\n");
        if( userp(me) && (int) me->query("organization/privs")!= -1 )
                return notify_fail("不是领导不可招募成员．\n");
        if((string)me->query("organization/org_name") ==
           (string)ob->query("organization/org_name"))
        if((int)me->query("organization/generation") >=
           (int)ob->query("organization/generation"))
                return notify_fail(ob->name()+"的辈分并不比你低！\n");
	// If the target is willing to join us already, we do it.
	if( (object)ob->query_temp("pending/join") == me ) {

		if( !living(ob) ) {
			message_vision(
				"$N决定收$n为成员。\n\n"
				"不过看样子$n显然没有办法行入帮之礼。\n\n",
				me, ob);
			return 1;
		}
		if(mapp(ob->query("organization")) &&
                   (string)me->query("organization/org_name") !=
                   (string)ob->query("organization/org_name") )
                {
         
                        message_vision("$N决定背叛原来的组织，改投入$n的组织\n\n"
                "$N跪了下来向$n恭恭敬敬地磕了一个响头，叫道：「大哥！」\n\n",
                        ob, me);
                        if(ob->query("score") > 5000) ob->add("score", -5000);
			ob->add("betrayer", 1);
		} else
			message_vision(
				"$N决定收$n为成员。\n\n"
				"$n跪了下来向$N恭恭敬敬地磕了一个响头，叫道：「大哥！」\n",
				me, ob);

		me->enroll_member(ob);
		ob->delete_temp("pending/join");

		write("恭喜你新收了一名成员！\n");
		organization = ob->query("organization");
		tell_object( ob, sprintf("恭喜您成为%s的第%s代成员。\n", organization["org_name"],
			chinese_number(organization["generation"]) ));

		return 1;
	

	} else {

		old_enr = me->query_temp("pending/enroll");
		if( ob==old_enr )
			return notify_fail("你想收" + ob->name() + "为成员，但是对方还没有答应。\n");
		else if( objectp(old_enr) ) {
			write("你改变主意不想收" + old_enr->name() + "为成员了。\n");
			tell_object(old_enr, me->name() + "改变主意不想收你为成员了。\n");
		}

		me->set_temp("pending/enroll", ob );
		message_vision("\n$N想要收$n为成员。\n", me, ob);
		tell_object(ob, YEL "如果你愿意加入" + me->name() + "的组织，用 join 指令。\n" NOR);
		return 1;
	}
}
/*

int help(object me)
{
        write(@HELP
指令格式 : enroll [cancel]|<对象>
 
这个指令能让你收某人为成员, 如果对方也答应要拜你为师的话.
 
HELP
        );
        return 1;
}
*/
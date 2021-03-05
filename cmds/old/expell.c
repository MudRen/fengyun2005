// expell.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    object ob;
    string *skname;
    string msg;
    mapping skills;
    int i;

    if( !arg || !ob = present(arg, environment(me)) )
        return notify_fail("你要将谁逐出师门？\n");

    if( !ob->is_character() )
        return notify_fail("你要开革「谁」？\n");

    if( !userp(ob) )
        return notify_fail("你只能开革玩家所扮演的人物。\n");

    if(!ob->is_apprentice_of(me) && 
       !(me->query("family/privs")==-1 &&
         (string)me->query("family/family_name")==
         (string)ob->query("family/family_name") &&
         (int)me->query("family/generation") >
         (int)ob->query("family/generation")))
        return notify_fail("这个人不是你的弟子。\n");
    
    message_vision("$N对著$n说道：从今天起，你再也不是我"
                   + me->query("family/family_name") +
                   "的弟子了，你走吧！\n", me, ob);
    
    msg=sprintf("%s(%s)被%s%s(%s)开革出『%s』了！",
                ob->name(1),ob->query("id"),
                me->query("family/title"),
                me->name(1),me->query("id"),
                me->query("family/family_name"));
    CHANNEL_D->do_sys_channel("info", msg);

    ob->assign_title("弃徒",1);
    ob->delete("family/master_id");
    ob->delete("family/master_name");
    
    skills = ob->query_skills();

    if( mapp(skills) )
    {
        skname = keys(skills);
        for(i=0; i<sizeof(skname); i++)
            skills[skname[i]] /= 2;
    }

    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : expell <某人>
 
这个指令可以让你开除不成才的弟子，被开除的弟子所有技能都会降到原来
的一半，而且综合评价一项会变成零，这对於一个人物而言是一个「比死还
严重」的打击，请你在开除一名弟子之前务必审慎考虑。
 
HELP
	);
    return 1;
}

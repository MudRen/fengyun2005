// scribe.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string spells, name, ob_name;
        object ob;

        // We might need to load new objects.
        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("( 你上一个动作还没有完成，不能画符！\n");

        if( (int)me->query("sen") < 15 )
                return notify_fail("你的精神太差了，无法画符。\n");

        if( !arg
        ||      sscanf(arg, "%s on %s", name, ob_name)!= 2 )
                return notify_fail("指令格式：scribe <符咒> on <物品>\n");

        if( !objectp(ob = present(ob_name, me)) )
                return notify_fail("你身上没有这样东西。\n");

        if( stringp(spells = me->query_skill_mapped("scratching")) ) {
               if (me->is_fighting()) me->start_busy(1);
               return( SKILL_D(spells)->scribe_spell(me, ob, name) );         
        } 
        return notify_fail("你请先用 enable scratching 指令选择你要使用的符咒系。\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	scribe <符咒名称> on <物品名称>[0m
[0;1;37m────────────────────────────────[0m   

在画符用的桃符纸(paper seal)或其他物品上画符，即使是相同的符咒，
画在不同的物品上也有可能有不同的效果。

在你画符之前，你必须先用 enable 指令来指定你要使用的咒文系。

注：画符会消耗若干气(要咬破手指用鲜血画)与神，画成的符咒可以用
	attach指令将它贴在目标物身上。

[0;1;37m────────────────────────────────[0m 
HELP
        );
        return 1;
}

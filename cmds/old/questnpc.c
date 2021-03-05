// by suu for questnpc
#include <ansi.h>
int main(object me, string str)
{
        string output;
        me->add("sen",-5);
        output =  YEL"┌──────────┐"NOR + RED"  风云2005血雨檄  "NOR + YEL"┌───────────┐\n"NOR;
        output += YEL"└──────────┘"NOR + CYN"~~~~~~~~~~~~~~~~"NOR + YEL"└───────────┘\n"NOR;
        output += QUESTNPC_D->dyn_evil_quest_list();
        output += YEL"┌───────────────────────────────┐\n"NOR;
        output += YEL"└───────────────────────────────┘\n"NOR;
		output += YEL"┌──────────┐"NOR + BLU"  风云2005正气榜  "NOR + YEL"┌───────────┐\n"NOR;
        output += YEL"└──────────┘"NOR + CYN"~~~~~~~~~~~~~~~~"NOR + YEL"└───────────┘\n"NOR;
        output += QUESTNPC_D->dyn_good_quest_list();
        output += YEL"┌───────────────────────────────┐\n"NOR;
        output += YEL"└───────────────────────────────┘\n"NOR;

        me->start_more("", output, 0);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: questnpc

这个指令是用来得知目前的所有被悬赏的NPC.

HELP
        );
        return 1;
}

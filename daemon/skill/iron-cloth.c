// iron-cloth.c

inherit SKILL;
#include <ansi.h>
void setup() {
	set("name","铁布衫");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",100);
	set("effective_level",50);
	set("absorb_msg", ({
		"$n已有准备，不慌不忙的运起铁布衫。\n",
        	"$n闭目凝神，气走全身，护体硬功达到巅峰状态。\n",
        	"$n「嘿」的一声，不躲不闪，运起铁布衫迎向$N！\n",
	}) );
}	
/*
void skill_improved(object me)
{
    int s;

    s = me->query_skill("iron-cloth", 1);
    if( s%10==9 && (int)me->query("fle") < s/5) {
        tell_object(me, HIW "由於你勤练铁布衫，你的韧性提高了。\n" NOR);
	me->set("fle",(s+1)/5);
    }
}

*/
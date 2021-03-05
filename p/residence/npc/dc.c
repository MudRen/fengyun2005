#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
      set_name("龙猫", ({ "totoro" }) );
    set("title", "胖胖的");
	set("race","野兽");
	setup();
}

int init()
{
	int i = random(3);
	switch (i)
	{
	case 0:
		set_temp("condition_type",CYN" <打盹中>"NOR);
		break;
	case 1:
		set_temp("condition_type",CYN" <睡眠中>"NOR);
		break;
	case 2:
		set_temp("condition_type",CYN" <零食中>"NOR);
		break;
	}
}
/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/


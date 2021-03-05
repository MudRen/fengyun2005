#include <ansi.h>
#include <combat.h>
inherit WALL;

void create()
{
	set_name("花丛之墙", ({ "wall of blossoms","wall" }) );
	set("race","元素");
	set("long","密密麻麻的坚藤构成了这堵墙壁，墙上每枝花，每片叶和\n每朵瓣都精确地相同。\n");
	set("combat_exp",0);
	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);


	set_skill("iron-cloth",200);
	set_skill("steelwall",200);
	map_skill("iron-cloth","steelwall");
	setup();
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

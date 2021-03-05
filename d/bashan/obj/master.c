#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("帝王谷 谷主「"HIY"黄衣客"NOR"」箫王孙", ({ "master xiao","master"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "帝王谷 谷主「"HIY"黄衣客"NOR"」箫王孙(Master xiao)。\n你凝神看去，却发现那只不过是尊石像．．．\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

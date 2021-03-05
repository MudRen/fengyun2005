
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(MAG"藏渊冥器"NOR, ({ "gift from hell", "gift"}) );
    set_weight(800);
    if (clonep())
    	set_default_object(__FILE__);
    else {
		set("unit", "个");
		set("real", "demon");
		set("long", "一个暗紫色的手工制品。\n");
    	set("value", 500);
    }
	::init_item();
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("腐烂的男尸", ({ "corpse"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这具尸体显然已经躺在这里有一段时间了，正散发著一股腐尸的味道。\n他的相貌吗... 都已经死了，还有什么好看的！\n\n");
		set("unit", "个");
		set("value", 0);
	}
	::init_item();
}



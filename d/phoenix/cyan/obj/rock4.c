// annie 07.2003
// dancing_faery@hotmail.com
//萧青湘
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("青石", ({ "青石" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
                set("long", "青石上是几行血红血红的大字：\n\n　　"HIR"一失足成千古恨　再回头已百年身\n\n　　　　　　　　　　　定元七年摩南答刻"NOR"\n\n算来，这块青石所刻的已经是数百年前的事情了。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

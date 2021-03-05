inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("观景台", ({ "观景台" , "platform", "scenery"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "二郎山有一观景台，实际上是一片悬崖，中间夹一沟，对面冰峰层叠，应
为上古冰川的尾端，庄严、静穆、沉吟不语。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }



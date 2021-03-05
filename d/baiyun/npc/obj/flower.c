
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(BLK"黑郁金香"NOR, ({ "flower"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "株");
        set("long","一朵名贵的黑郁金香。散发着淡淡的芳香。。\n");
        set("value",4000);
	}
}




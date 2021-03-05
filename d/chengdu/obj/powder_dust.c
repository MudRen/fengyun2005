#include <ansi.h>
//#include <weapon.h>

inherit COMBINED_ITEM;

void create()
{
	set_name("残留的火药灰", ({ "powder dust" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
"设计后没有充分燃烧的火药尘埃。"
);
		set("unit", "堆");
		set("base_unit", "堆");
		set("base_weight", 70);
		set("base_value", 0);
		set("volumn",1);
	}
	set_amount(1);
}


inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("密件", ({ "plan" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long", "一封密件，上面写着：子时，城隍庙，黑衣人。\n");
		set("value", 1);
	}
}




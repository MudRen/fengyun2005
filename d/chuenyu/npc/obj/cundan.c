
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("银票", ({ "cundan"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "一张淳于怀太在某个钱庄的存单。\n");
		set("value", 1);
	}
}




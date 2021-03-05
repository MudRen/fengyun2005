// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;


void create(){
	set_name(HIG"明烟草"NOR, ({"grass" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一株青翠欲滴的小草。\n");
		set("unit", "株");
		set("real_flower",3);
	}
    ::init_item();
}


// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;

void create(){
	set_name(HIR"茵生草"NOR, ({"grass" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一株奇异的小草，叶瓣八分，鲜红如血。\n");
		set("unit", "株");
		set("no_drop",1);
		set("real_flower",2);
	}
    ::init_item();
}


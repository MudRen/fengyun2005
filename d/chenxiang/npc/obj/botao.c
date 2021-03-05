// pink_cloth.c

#include <armor.h>

inherit NECK;

void create()
{
	set_name("玉脖套", ({ "botao"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个缅玉脖套，大约有八寸宽，大腿粗细。\n");
		set("unit", "个");
		set("value", 0);
		set("no_drop",1);
		set("wear_msg", "$N把一个$n套在头上。\n");
		set("unwield_msg", "$N把$n从头上除了下来。\n");
	}
	::init_neck();
}


inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"胭脂"NOR, ({ "yanzhi" , "胭脂"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "盒");
		set("long", "鲜红似血的上等胭脂\n");
		set("value", 1000);
	}
}




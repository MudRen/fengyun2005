inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("货票", ({ "huopiao"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long", "一封金狮镖局的货票。\n");
		set("value", 100);
	}
}




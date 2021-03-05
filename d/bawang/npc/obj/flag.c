inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("镖旗", ({ "flag"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "面");
		set("long", "一面金边的小镖旗，上面写着“中原“二字。\n");
		set("value", 1);
	}
}





#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
	set_name("马鬃木刷" , ({ "brush" }) );
	set_weight(70000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("value", 400);
		set("material", "wood");
	}
	::init_whip(20);
}

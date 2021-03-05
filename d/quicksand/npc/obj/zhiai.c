// icy_band.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(BLK"黑纱"NOR, ({ "black ribbon", "ribbon" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 400);
		set("material", "cloth");
		set("armor_prop/armor", 5);
	}
	::init_head();
}

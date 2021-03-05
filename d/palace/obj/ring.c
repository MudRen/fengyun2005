
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
	set_name(CYN"豹牙手环"NOR, ({ "shouhuan"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个透着森森寒气的手环\n");
		set("unit", "个");
		set("value", 300);
		set("armor_prop/astral_vision", 1);
		set("wear_msg", "$N轻轻地把一个$n戴在手腕上。\n");
		set("unwield_msg", "$N轻轻地把$n从手腕上除了下来。\n");


	}
	::init_finger();
}


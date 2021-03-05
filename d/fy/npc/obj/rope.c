#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name(HIW"五彩绳子"NOR, ({ "colorful rope", "rope" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条五六寸长的绳子，是用五种不同颜色的丝绳编起来的。\n");
		set("unit", "条");
		set("value", 6);
		set("armor_prop/armor", 0);
		set("wear_msg", "$N轻轻地把一条$n绑在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
		set("female_only", 1);
		set("colorfulrope",1);

	}
	::init_head();
}


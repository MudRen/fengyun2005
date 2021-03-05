#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name(RED"红色佛珠"NOR, ({ "red bead", "bead" }) );
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 700);
		set("material", "stone");
		set("wear_msg", "$N拿出一条$n，摩挲了几下，然後戴在颈上。\n");
	        set("unwear_msg", "$N藏起手中的$n。\n");
	}
	::init_neck();
}

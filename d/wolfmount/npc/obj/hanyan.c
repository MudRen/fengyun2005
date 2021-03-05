#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name(HIW"旱烟枪"NOR, ({ "hanyan" }) );
    set_weight(60000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "这是一把乌铁旱烟枪，杆长三尺，烟斗硕大宛似铜锤。\n");
		set("value", 5);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声把$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n收了起来。\n");
	}
    ::init_hammer(10);
}

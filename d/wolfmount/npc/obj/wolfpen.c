#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
	set_name(WHT"狼毫笔"NOR, ({ "wolf pen" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("jungle",1);
		set("material", "iron");
		set("value", 600);
		set("long", "这是一管做工精细的狼毫毛笔。\n");
		set("wield_msg", "$N拿出一支$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n放入怀中。\n");
	}
	::init_staff(2);
}

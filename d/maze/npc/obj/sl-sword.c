#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name("铁条", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一根两尺长的铁条，好像是从什么地方拗断下来的。\n");
		set("value", 400);
		set("nodrop_weapon",1);
		set("material", "steel");
		set("wield_msg", "$N把别在腰间的$n拔出握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间。\n");
	}
	init_sword(35);
}

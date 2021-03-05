//By clone       6/2001
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name("细短小剑" , ({ "short sword","sword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把短小的剑，剑身极窄。\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "精光一闪---$N「唰」地一声把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	::init_dagger(10);
}

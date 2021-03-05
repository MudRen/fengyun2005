
#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
	set_name(HIR"金枪"NOR, ({ "gold spear" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一金煌煌的金枪，份量大约有十来斤左右。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入地下。\n");
	}
	::init_spear(15);
}

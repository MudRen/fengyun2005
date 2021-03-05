#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name(HIM"紫霜软剑"NOR, ({ "soft sword", "sword" }) );
    set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "把");
        set("value", 1000);
        set("long", "剑长四尺，灵动如蛇，端是一把利器。\n");
        set("material", "steel");
        set("rigidity", 100);
        set("wield_msg", "$N从腰间抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n缠回腰间。\n");
	}
    ::init_sword(20);
}

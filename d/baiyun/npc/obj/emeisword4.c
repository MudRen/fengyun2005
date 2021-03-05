// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(WHT"云之剑"NOR, ({ "yun sword","sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "这是峨眉掌门独孤一鹤赠于四个女弟子的防身利剑，
每一把上娟秀的刻着四秀的名，这把上刻的是“云”。\n");
        set("value", 10);
		set("material", "steel");
	}
    ::init_sword(15);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");


}

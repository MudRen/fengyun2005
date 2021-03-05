#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
    	set_name(HIW"冰魄寒光刀"NOR, ({ "ice blade","blade" }) );
		set_weight(7000);
		if( clonep() )
		set_default_object(__FILE__);
		else {
		set("unit", "把");
        set("long", "冰魄寒光刀,每一刀劈出,俱是冰之魂、雪之魄、霜之灵、寒之胆。\n");
        set("value", 900);
        set("level_required",100);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
    	init_blade(70);
}

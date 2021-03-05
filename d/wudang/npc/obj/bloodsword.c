// sword.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIR"血剑"NOR, ({ "blood sword","sword" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "一把极窄极长，血槽很深的长剑。\n");
		set("value", 200);
		set("material", "steel");
		set("rigidity", 80);
		set("wield_msg", "$N从剑鞘中抽出一把闪闪发光的$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
    ::init_sword(23);
}

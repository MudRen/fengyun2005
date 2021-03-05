// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(CYN"墨子剑"NOR, ({ "mozi sword","sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "这把剑大巧不工，无刃而利，形式古朴，竟是春秋时墨家巨子的佩剑，价值连城。\n");
        set("value", 2000);
        set("no_get",1);
		set("material", "steel");
	}
    ::init_sword(60);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");


}

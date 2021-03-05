// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIW"含光"NOR, ({ "hanguang sword","sword" }) );
    set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "殷三名剑之一，见剑不见刃，锋刃所触之所，无痛无血，已\n命赴黄泉。\n");     
        set("value", 600);
		set("material", "steel");
	}
    ::init_sword(10);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");


}

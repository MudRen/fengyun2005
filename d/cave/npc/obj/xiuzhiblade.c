// Tie@fengyun
#include <weapon.h>

inherit DAGGER;

void create()
{
    set_name("修指刀", ({ "finger dagger","dagger" }) );
        set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "一把小小的修指刀。。\n");
        set("value", 300);
		set("material", "steel");
        set("wield_msg", "$N手掌一翻，一把$n赫然握在手中。\n");
        set("unwield_msg", "$N小心翼翼将手中的$n插入皮鞘。\n");
	}
    ::init_dagger(10);
}

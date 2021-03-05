#include <ansi.h>
#include <weapon.h>

inherit SWORD;
void create()
{
	set_name("寒玉短剑", ({ "jade sword", "sword"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 0);
		set("material", "stone");
		set("rigidity", 2000);
		set("long", "一把非金非铁的小剑，透着玉色的光芒。\n");
		set("wield_msg", "$N抽出一把$n，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	::init_sword(10);
}


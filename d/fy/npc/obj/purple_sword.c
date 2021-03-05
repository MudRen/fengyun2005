#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("幽冥紫灵剑", ({ "hell sword", "sword" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 100);
		set("material", "stone");
		set("long", "一把非金非铁的宝剑，似乎透着紫色的光芒。\n");
		set("wield_msg", "$N抽出一把透着紫色的光芒的剑，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	::init_sword(1);
}

/*
int query_autoload() { 
	return 1; 
}*/
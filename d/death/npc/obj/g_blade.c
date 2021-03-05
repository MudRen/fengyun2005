#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create() {
    set_name(HIC"青龙偃月刀"NOR, ({ "qinglong blade","blade" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        	set("value", 100);
		set("material", "iron");
        	set("long", "一柄长二丈，九十斤重的大刀，十分锋利。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	
	::init_blade(10);
}

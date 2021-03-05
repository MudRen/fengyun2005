#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("竹片", ({ "zhu pian", "bamboo", "竹片" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 10);
		set("material", "wood");
		set("long", "一个青绿色的竹片，上面依稀刻着一幅山水图。\n");
	    set("wield_msg", "$N拿出一个绿竹片握在手中。\n");
	    set("unequip_msg", "$N放下手中的$n。\n");
	}
	::init_sword(2);
}


// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(HIR"浸满血渍的锦服"NOR, ({ "cloth","jin cloth" }) );
    set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
        set("long", "这是件高贵的锦服但如今已经满是血迹。。。\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 2);
	}
	::init_cloth();
}

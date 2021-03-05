#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
    set_name(HIC"蓝色百褶裙"NOR, ({ "long skirt","skirt" }) );
    set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
		else {
		set("unit", "件");
        	set("long", "一件蓝色百褶裙，婀娜多姿，可可动人。\n");
        	set("value", 40);
		set("material", "cloth");
        	set("armor_prop/armor", 10);
		set("female_only", 1);
	}
	::init_cloth();
}

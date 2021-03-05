#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIM"紫蟒袍"NOR, ({"mang pao", "pao"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
                set("material", "cloth");
                set("long", "一间华丽的紫蟒袍，上绣龙蟒九条，镶金缀玉。\n");
                set("unit", "件");
                set("value", 1000);
                set("armor_prop/armor", 2);
        }
	::init_cloth();
}
// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(HIG"翡翠撒花洋褶裙"NOR, ({ "huaskirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件翡翠长裙体现成熟女子婀娜身姿，风韵昭然。\n");
		set("material", "cloth");
        set("value", 1000);
         set("armor_prop/armor", 3);
		set("female_only", 1);
	}
	::init_cloth();
}

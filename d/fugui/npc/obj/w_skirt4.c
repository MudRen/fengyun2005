// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(BLU"广袖合欢袄"NOR, ({ "blueskirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
        set("value", 1000);
         set("armor_prop/armor", 3);
		set("female_only", 1);
	}
	::init_cloth();
}

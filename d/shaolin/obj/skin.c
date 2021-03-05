// TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("神牛皮", ({ "buffalo skin" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("material", "leather");
                set("for_create_cloth",1);
                set("armor_prop/armor", 13);
		set("long","一块坚硬无比的神牛皮。\n");
		set("max_enchant",6);
                set("base_armor",13);
		set("value",1000);
        }
        ::init_cloth();
}

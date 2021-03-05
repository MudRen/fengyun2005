// TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("蛰龙皮", ({ "dragon skin","skin" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("material", "leather");
                set("for_create_cloth",1);
                set("armor_prop/armor", 20);
		set("long","沙海蛰龙的龙皮，是制造护甲的上选材料。\n");
		set("max_enchant",6);
                set("base_armor",15);
		set("value",100000);
        }
        ::init_cloth();
}

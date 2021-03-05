// TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("粗麻布", ({ "mabu" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("material", "cloth");
                set("for_create_cloth",1);
		set("base_armor",10);
                set("armor_prop/armor", 10);
		set("long","一块又厚又结实的麻布。\n");
		set("max_enchant",3);
		set("value",4000);
        }
        ::init_cloth();
}

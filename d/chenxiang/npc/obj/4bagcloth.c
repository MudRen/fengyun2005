// TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("四袋布衣", ({ "4bag-cloth" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 2);
		set("value",400);
        }
        ::init_cloth();
}

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("灰袍", ({"gray cloth", "cloth"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("long", "一件灰暗的布袍，穿在身上一丝人气也没有．\n");
                set("unit", "件");
                set("value", 200);
                set("armor_prop/armor", 5);
        }
        ::init_cloth();
}

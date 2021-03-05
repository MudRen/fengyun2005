// TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
    set_name("黑纱蝉衣", ({ "black silky cloth" }) );
    set_weight(100);
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

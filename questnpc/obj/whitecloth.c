#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIW"白袍"NOR, ({ "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
    ::init_cloth();
}

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIR"绣花布袍"NOR, ({ "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        ::init_cloth();
}

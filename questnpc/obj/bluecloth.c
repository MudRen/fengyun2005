#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(BLU"宝蓝长袍"NOR, ({ "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是一套宝蓝色的长袍，雍容华贵。\n");
                set("material", "cloth");
                set("armor_prop/armor", 5);
        }
        ::init_cloth();
}

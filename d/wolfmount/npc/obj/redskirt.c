#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
    set_name(HIR"大红缎裙"NOR, ({ "red skirt", "skirt" }) );
    set_weight(1800);
    if( clonep() )
        set_default_object(__FILE__);
    else {
    set("long", "一袭长裙，上面绣了几道水波．\n");
        set("unit", "袭");
        set("value", 3);
        set("material", "cloth");
        set("armor_prop/armor", 5);
      }
    ::init_cloth();
}

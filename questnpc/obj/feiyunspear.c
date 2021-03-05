#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
        set_name( HIC "飞云枪" NOR, ({ "feiyunspear","spear" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把镔铁短枪。");
                set("value", 150000);
                set("material", "iron");

        }
        ::init_spear(100);
}

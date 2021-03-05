#include <weapon.h>

inherit BLADE;
#include <ansi.h>

void create()
{
        set_name(BLK"鬼头断门刀"NOR, ({ "duanmen blade","blade" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把三十六斤的鬼头刀，血槽里满是鲜血。。\n");
                set("value", 100);
		set("rigidity", 2000);
                set("material", "steel");
        }
        ::init_blade(10);
}

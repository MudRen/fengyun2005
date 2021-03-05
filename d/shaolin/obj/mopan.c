#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("石磨盘", ({ "giant mo" }) );
        set_weight(600000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "明代一个大石磨盘，硕大无朋，据说当年所有僧众
所需食物，豆腐都是这个磨盘所磨。\n");
                set("value", 3);
                set("material", "iron");
        }
        init_hammer(650);
}

#include <armor.h>
inherit WRISTS;

void create() {
        set_name("皮革护臂", ({ "leather sleeves"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一只上好小牛皮做的护臂。\n");
                set("unit", "只");
                set("value", 50);
                set("wear_msg", "$N把一个$n戴在手臂上。\n");
                set("unequip_msg", "$N把$n从手臂上除了下来。\n");
        }
        ::init_wrists();
}

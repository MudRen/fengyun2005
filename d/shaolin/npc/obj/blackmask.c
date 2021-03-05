#include <armor.h>
inherit MASK;

void create() {
        set_name("黑色面巾", ({ "blackmask"}) );
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块黑色的蒙面纱。\n");
                set("material", "cloth");
                set("unit", "快");
                set("value", 3);
                set("wear_msg", "$N轻轻地把$n罩在脸上。\n");
                set("unwield_msg", "$N轻轻地把$n从脸上除了下来。\n");
        }
        ::init_mask();
}

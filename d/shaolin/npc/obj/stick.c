// staff.c : Gun zi

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("僧棍", ({ "monk-stick" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根看起相当普通的僧棍");
                set("value", 300);
                set("material", "wood");
        }
        init_staff(30);
        set("wield_msg", "$N把$n紧紧地握在手中。\n");
        set("unwield_msg", "$N松开了手中的$n。\n");
}

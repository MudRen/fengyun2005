
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("破弯刀", ({ "blade" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把生了锈、崩了口儿的弯刀");
                set("value", 5);
                set("material", "steel");
        set("wield_msg", "$N从腰间抽出一把生了锈、崩了口儿的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n别在腰间。\n");
        }
        ::init_blade(7);



}


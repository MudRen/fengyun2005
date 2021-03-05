// sixhammer.c
#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
        set_name("凤头斧", ({ "axe" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是沙场上将士常用的凤头斧。\n");
                set("value", 1);
                set("material", "iron");
                set("wield_msg", "$N从背后抽出$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_axe(4);
}

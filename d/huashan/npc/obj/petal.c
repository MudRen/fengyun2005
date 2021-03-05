#include <weapon.h>
inherit THROWING;

void create()
{
    set_name("桃花瓣", ({ "petal" , "桃花瓣"}) );
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "把");
        set("long", "粉红色的桃花瓣上还挂着几滴露珠。\n");
        set("base_unit", "片");
        set("base_value", 1);
        set("base_weight", 1);
        set("marks/deerfood", 1);
    }
    set_amount(1);
    ::init_throwing(2);
}



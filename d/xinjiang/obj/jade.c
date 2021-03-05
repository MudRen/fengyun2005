#include <armor.h>

inherit NECK;

void create()
{
        set_name("白玉坠儿", ({ "jade", "white jade"}) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个晶莹剔透的白玉坠儿，据说戴着它在沙漠里行走可以辟邪。\n");
                set("unit", "个");
                set("value", 500);
                set("wear_msg", "$N轻轻地把一个$n挂在脖子上。\n");
                set("unwield_msg", "$N轻轻地把$n从脖子上除了下来。\n");


        }
        ::init_neck();
}



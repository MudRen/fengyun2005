#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
    set_name(MAG"带血的紫藤花瓣儿"NOR, ({ "blood petal" , "petal"}) );
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "瓣");
        set("long", "一滴鲜血正沿着紫藤花瓣儿流下. \n");
        set("base_unit", "瓣");
        set("base_value", 1);
        set("base_weight", 1);
    }
    set_amount(1);
    ::init_throwing(2);
}
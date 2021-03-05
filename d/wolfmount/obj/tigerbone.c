#include <weapon.h>
inherit HAMMER;
void create()
{
    set_name("虎骨", ({ "tiger bone","bone" }) );
    set_weight(15000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "具");
    set("long", "这是具老虎的骸骨，颈骨似锤柄，虎头硕大似铜锤一般。\n");
        set("value", 3);
        set("material", "iron");
    }
    ::init_hammer(10);
}

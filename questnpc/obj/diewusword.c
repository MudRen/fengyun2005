#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIY"蝶舞剑"NOR, ({ "diesword","sword" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把一尺三寸长的短剑，剑柄上是彩蝶飞舞的图案。\n");
                set("value", 90000);
                set("material", "steel");
        }
        ::init_sword(75);

}

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIG"秋水剑"NOR, ({ "qiushui sword","sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把碧若秋水的长剑。\n");
                set("value", 40000);
                set("material", "steel");
        }
        ::init_sword(60);

}

// jinchui.c
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name(HIY"金瓜"NOR, ({ "golden hammer", "hammer" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "金瓜的分量十足，砸到头上可不好玩。\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        ::init_hammer(15);
}

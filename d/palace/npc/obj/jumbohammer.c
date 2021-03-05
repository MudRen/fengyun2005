// hammer.c

#include <weapon.h>

inherit HAMMER;
#include <ansi.h>
void create()
{
        set_name(HIG"毁天锤"NOR, ({ "jumbohammer" }) );
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个沉重的毁天锤，打造的相当坚实。\n");
                set("value", 300);
                set("material", "iron");
                set("wield_msg", "$N拿出一双$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(60);
}

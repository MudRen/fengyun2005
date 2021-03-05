// hammer.c
#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name(HIR"枷铐"NOR, ({ "jiakao" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
                set("long", "这是一副沈重的枷铐，打造的相当坚实。\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        ::init_hammer(15);
}

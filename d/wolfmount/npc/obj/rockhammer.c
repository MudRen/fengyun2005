#include <ansi.h> 
#include <weapon.h> 
inherit HAMMER;

void create()
{
        set_name( HIB"搏浪锤"NOR, ({ "wave-hammer" }) );
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一把样式古拙的大铁锤，重约一百八十斤。 \n");
                set("material", "gold");
                set("rigidity", 200000); 
                set("wield_msg", "$N舌绽惊雷，怒喝中霍然拎出一把$n，掂了掂份量，握在手中。\n");
                set("unwield_msg", "$N缓缓放下手中的$n。\n");
        }
        ::init_hammer(20);
}

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(HIR"滴血的红玫瑰"NOR, ({ "blood rose", "rose" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一束绽放着的红玫瑰，但花瓣上流淌着一滴滴鲜血。\n");
                set("unit", "朵");
                set("value", 100);
                set("material", "plant");
                set("armor_prop/armor", 0);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");

                set("female_only", 1);

        }
        ::init_head();
}

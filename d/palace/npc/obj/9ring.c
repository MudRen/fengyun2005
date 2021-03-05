#include <weapon.h>
inherit HAMMER;
#include <ansi.h>

void create()
{
        set_name(HIB"九金乌环"NOR, ({ "jiujin","hammer" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "九金乌环：据说是用九种不同性质的乌金铸成的环，坚硬度极高。\n");
                set("value", 3000);
                set("material", "iron");
                set("level_required",150);
                set("wield_msg", "$N双手一分，掏出一对$n。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_hammer(80);
}

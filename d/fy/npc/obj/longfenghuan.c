#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(HIY"龙"HIG"凤"HIR"双环"NOR, ({ "longfeng" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一金一银的一对环，金环刻龙，银环绘凤，入手有相当的份量。\n");
                set("value", 3000);
                set("no_get",1);
                set("material", "iron");
                set("wield_msg", "$N双手一分，拿出一双$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        ::init_hammer(60);
}

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name(HIC"鬼牙玄冥杖"NOR, ({ "ghoststaff" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是一把似金非金，似石非石的宝杖，身上刻著许多你从未见过的魔符。\n");
                set("value", 10);
                set("material", "steel");
                set("wield_msg", "$N拿出一根似金非金，似石非石的$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
		set("weapon_prop/astral_vision", 1);
        }
        init_staff(2);
}

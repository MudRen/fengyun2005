#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name( "长篙" , ({ "changgao" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "一杆竹作的长篙\n");
                set("value", 4000);
                set("material", "steel");
                set("wield_msg", "$N一伸手抄起$n。\n");
                set("unwield_msg", "$N将手中的$n插入地下。\n");
        }
        ::init_staff(6);
}

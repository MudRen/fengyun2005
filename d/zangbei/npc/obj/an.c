#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("皮制的驼鞍", ({ "tuoan" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long","装在骆驼背上用来固定货物的架子。\n");
                set("material", "lether");
                set("armor_prop/armor", 20);
                set("value",10);
                set("wear_msg","$N拿出一个驼鞍，往自己背上一放，费了半天劲才把它固定好。\n");
                set("unequip_msg","$N把$n从身上卸了下来，大大地喘了口气。\n");
        }
        ::init_cloth();
}

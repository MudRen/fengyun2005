// TIE@FY3
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("五彩布", ({ "caibu" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "块");
            set("for_create_cloth",1);
            set("base_armor",4);
            set("material", "cloth");
            set("armor_prop/armor", 4);
    		set("long","一块从外藩进贡来的布块，非绸非麻，也不知是什么材料。\n");
    		set("max_enchant",6);
    		set("value",40000);
        }
        ::init_cloth();
}

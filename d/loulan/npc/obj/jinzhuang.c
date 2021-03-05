#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
        set_name(CYN"织锦劲装"NOR, ({"silk cloth", "cloth"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("long", "一件急风三十六骑弟子专备的织锦劲装。\n");
                set("unit", "件");
                set("value", 200);
                set("armor_prop/armor", 5);
        }
	::init_cloth();
}
inherit EQUIP;
#include <ansi.h>

void create()
{
        set_name(CYN"洒金斗篷"NOR, ({"gold robe", "robe"}));
        set_weight(2000);
        set("material", "cloth");
        set("long", "一件急风三十六骑弟子专备的洒金斗篷，斗篷一角绣着“李义骑”。\n");
        set("unit", "件");
        set("value", 2);
        set("item_owner","李义骑");
        set("fakegender", "男性");
        set("armor_type", "mask");
        set("armor_prop/armor", -10);
        set("armor_prop/name",({"李义骑"}));
        set("armor_prop/id", ({"li yiqi"}) );
}
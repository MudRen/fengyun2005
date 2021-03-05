// cloth.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(CYN"青绸衫"NOR, ({"qing shan", "cloth"}) );
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
		set("unit", "件");
		set("long", "一件淡青色的丝绸长衫。");
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("value",1000);
    }
    ::init_cloth();
}

// cloth.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(BLU"绸缎袍"NOR, ({"silk cloth", "cloth"}) );
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
		set("unit", "件");
		set("long", "
一件巨大的绸缎袍子，上好的绸料上绣着些精致的花草。一看就知道
售价不凡，可却俗气得令人无奈。\n");
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value",1000);
    }
    ::init_cloth();
}

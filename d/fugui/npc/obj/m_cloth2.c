// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
    set_name(HIY"百蝶穿花箭袖袍"NOR, ({ "yellowcloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一穿上去，顿时令人似谦谦君子，温润如玉。\n");
		set("material", "cloth");
		set("value", 1000);
        set("armor_prop/armor", 1);
	}
	::init_cloth();
}

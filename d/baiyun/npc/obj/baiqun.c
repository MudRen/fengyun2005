#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
    set_name(HIW"白裙"NOR, ({ "baiqun" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "件");
        set("long", "一件宽大的白色长裙。\n");
		set("material", "cloth");
		set("value", 20);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}

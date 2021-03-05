#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIW"狐皮袄"NOR, ({"foxfur"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
                set("material", "cloth");
                set("long", "一件用狐皮做成的大袄。\n");
                set("unit", "件");
                set("value", 1000);
                set("armor_prop/armor", 10);
        }
	::init_cloth();
}
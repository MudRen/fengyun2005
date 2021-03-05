#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIW"白纱"NOR, ({ "baisha" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "件");
		set("long", "一件动人的白纱宫装，似乎什么也遮不住。\n");
		set("material", "cloth");
		set("value", 2);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}

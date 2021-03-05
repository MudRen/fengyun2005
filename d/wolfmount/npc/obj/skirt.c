#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIG"轻纱长裙"NOR, ({ "long skirt", "skirt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("long", "一条朦朦胧胧的纱裙，闻起来还有一股淡香。\n");
		set("unit", "条");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
	}
	::init_cloth();
}

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIW"雪羽披风"NOR, ({ "cloth" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件雪鸟羽毛编织成的雪白披风。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
		set("value", 10);
	}
	::init_cloth();
}

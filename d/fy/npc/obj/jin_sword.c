#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(CYN"无鞘之剑"NOR, ({ "sword" }) );
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 500);
		set("material", "steel");
		set("long", "一把没有剑锷的剑，剑身很薄，很轻，却相当韧，剑刃隐隐泛着青光。\n");
	}
	::init_sword(20);
}

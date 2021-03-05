//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
    set_name(YEL "月光刀" NOR, ({ "moonblade" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把窄窄的短刀，仿佛如月光一般。\n");
		set("value", 1000);
		set("material", "steel");
		set("for_yueshen",1);
	}
    ::init_blade(30);
}

#include <ansi.h>
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name(HIR"红石"NOR, ({ "red stone", "stone" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",HIR"石头竟是血红色的，红得可怕。\n"NOR);
		set("unit", "块");
		set("base_unit", "粒");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(30);
}

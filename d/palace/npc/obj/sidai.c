// echowhip.c

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name( HIM "天蚕丝带" NOR, ({ "sidai", "whip" }) );
	set_weight(17000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 1000);
		set("material", "leather");
		set("rigidity", 70);
		set("wield_msg", "$N从腰间解下一条$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n缠回腰间。\n");
	}
    init_whip(80);
}

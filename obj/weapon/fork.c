// fork.c

#include <weapon.h>
inherit FORK;

void create()
{
	set_name("钢叉", ({ "fork" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 1);
		set("long", "这是一把看起相当普通的钢叉");
                set("material", "steel");
                set("wield_msg", "$N把$n紧紧地握在手中。\n");
		set("unwield_msg", "$N松开了手中的$n。\n");
	}
	::init_fork(30);
}


#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name("狼腿", ({ "wolf leg"}) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
        	set("long", "这是一块从死狼身上扯下来的大腿，似乎可以当兵刃使。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N不知从什么地方摸出一把血淋淋的$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n收起。\n");
	}
    ::init_hammer(20);
}

#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
	set_name(HIR"红麝串"NOR, ({ "redlace"}) );
	set_weight(15);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条红麝串,如断肠人的心扉。\n");
		set("unit", "个");
		set("value", 500000);
		set("wear_msg", "$N轻轻地把一个$n戴在脖子上。\n");
		set("unwield_msg", "$N轻轻地把$n除了下来。\n");
		set("female_only", 1);
        }
        ::init_neck();
}


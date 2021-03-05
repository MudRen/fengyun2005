
#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
	set_name(HIC"九龙佩"NOR, ({ "necklace"}) );
	set_weight(15);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个九龙佩,凉意沁人，大快人心。\n");
		set("unit", "个");
		set("value", 500000);
		set("wear_msg", "$N轻轻地把一个$n戴在脖子上。\n");
		set("unwield_msg", "$N轻轻地把$n除了下来。\n");
		set("female_only", 1);
        }
        ::init_neck();
}


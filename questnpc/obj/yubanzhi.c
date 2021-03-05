
#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
	set_name(HIC "汉玉扳指" NOR, ({ "jade-ring"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		
		set("unit", "个");
		set("value", 50000);
        set("armor_prop/armor", 20);
      set("armor_prop/damage", 10);
		set("wear_msg", "$N轻轻地把一个$n戴在手指上。\n");
		set("unwield_msg", "$N轻轻地把$n从手指上除了下来。\n");


	}
        ::init_finger();
}


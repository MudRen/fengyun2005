
#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
	set_name(HIM"束发嵌宝紫金冠"NOR, ({ "goldenhat"}) );
	set_weight(23);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个名贵的束发嵌宝紫金冠。\n");
		set("unit", "顶");
		set("value", 500000);
		set("armor_prop/armor", 1);
		set("wear_msg", "$N轻轻地把一个$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
        }
        ::init_head();
}


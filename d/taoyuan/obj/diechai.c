// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("蝶钗", ({ "die chai", "chai" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "通体碧绿的玉钗上精工雕刻着一个栩栩如生的小粉蝶。\n");
		set("unit", "个");
		set("value", 1000);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("wear_msg", "$N轻轻地把一个$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");

		set("female_only", 1);

	}
	::init_head();
}


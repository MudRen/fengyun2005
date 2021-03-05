// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("紫罗兰", ({ "purple flower", "flower" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "高贵典雅的紫罗兰，闻起来还有一股淡淡的香味儿。\n");
		set("unit", "朵");
		set("value", 6);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
		set("female_only", 1);

	}
	::init_head();
}


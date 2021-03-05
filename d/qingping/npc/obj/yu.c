// pink_cloth.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("白玉佩", ({ "yu pei"  }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "玉佩不大但晶莹剔透，上面用一根红线穿着。\n");
		set("unit", "个");
		set("value", 6);
		set("material", "plant");
		set("armor_prop/armor", 0);
		set("wear_msg", "$N地$n套到了脖子上。\n");
		set("unwield_msg", "$N轻轻地把$n从颈上摘了下来。\n");
	}
	::init_head();
}


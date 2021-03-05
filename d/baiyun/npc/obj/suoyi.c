// raincoat.c

#include <armor.h>

inherit SURCOAT;

void create()
{
    set_name("滴水不沾的破旧蓑衣", ({ "rain coat","coat" }) );
    set_weight(70000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "plant");
		set("unit", "件");
                set("long", "无论从里到外怎么看,这都是一件再普通不过的破旧蓑\n衣,但奇怪的是穿在这老人身上,怒海狂涛中竟滴水不沾.\n");
        set("value", 0);
        set("armor_prop/armor", 10);
	}
	::init_surcoat();
}

#include <weapon.h>
inherit HAMMER;

void create()
{
    set_name("花竹篮", ({ "basket", "flower basket" }) );
	set_weight(500);
    if( clonep() )
		set_default_object(__FILE__);
  	else {
		set("long", "一个盛满鲜花的小竹篮。\n");
		set("prep", "in");
        set("unit", "个");
        set("value", 20);
        set("material", "wood");
    }
	::init_hammer(1);
}


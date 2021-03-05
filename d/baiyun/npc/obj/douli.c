// hat.c
#include <armor.h>

inherit HEAD;

void create()
{
    set_name("一尘不染的青竹斗笠", ({ "rain hat" ,"hat"}) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
        set("value", 0);
		set("material", "wood");
        set("armor_prop/armor", 1);
       set("long", "一顶很普通的渔家出海常戴的斗笠,似乎很陈旧了,但却一尘不染,干干净净.\n");
	}
	::init_head();
}

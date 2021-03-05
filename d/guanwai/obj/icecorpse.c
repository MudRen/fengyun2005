
inherit ITEM;
#include <ansi.h>

void create()
{
    set_name(HIW"冰尸"NOR, ({ "frozen corpse" , "corpse"}) );
    set_weight(20000+random(30000));
	set_max_encumbrance(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
        set("long", "一具被冰封冻住的尸骨,面目如昨,似乎你都可以感觉到他死时的恐惧..\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }



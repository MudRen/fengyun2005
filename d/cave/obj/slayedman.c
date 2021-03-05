
inherit ITEM;
#include <ansi.h>

void create()
{
    set_name(HIR"开膛破肚的残缺尸体"NOR, ({ "slayed corpse"}) );
    set_weight(20000+random(30000));
	set_max_encumbrance(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
        set("long", "一具还冒着不知热气还是血气的尸体，开膛破肚，狼藉一片。。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }



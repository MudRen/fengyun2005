// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
    	set_name("龙泉宝剑", ({ "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        set("long", "这是沙场上将士佩戴的宝剑。\n");
        set("value", 1);
		set("material", "steel");
	}
    	init_sword(4);
}

// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    	set_name(HIG"断门剑"NOR, ({ "duanmen sword","sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
        	set("long", "宝剑断门,饮血方归。\n");
        	set("value", 90);
		set("material", "steel");
	}
    	init_sword(20);

}

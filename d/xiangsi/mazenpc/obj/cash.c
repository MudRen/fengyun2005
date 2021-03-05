#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("雪泥", ({"mud","mud_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一堆看起来稀烂的泥巴，或许可以用作武器。\n");
		set("unit", "堆");
		set("base_value", 1000);
		set("item_damaged",1);
		set("base_unit", "堆");
		set("base_weight", 3);
		set("lore",1);
		set("volumn",1);
	}
	set_amount(10);
	init_throwing(100);
}


    
/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

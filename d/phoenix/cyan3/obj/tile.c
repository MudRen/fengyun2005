
#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("碎瓦片", ({ "tile" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一块破碎的瓦片。\n");
		set("unit", "块");
		set("base_unit", "块");
		set("base_weight", 100);
	}
	set_amount(1);
	::init_throwing(100);
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


#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("柳条", ({ "willow" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一根细长细长的柳条。\n");
		set("unit", "根");
	}
	::init_whip(1);
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

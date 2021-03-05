#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name("宝蓝长衫", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 3);
	}
	::init_cloth();
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


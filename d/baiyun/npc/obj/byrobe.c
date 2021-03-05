#include <armor.h>
inherit CLOTH;
#include <ansi.h>

void create()
{
	set_name(HIY"黄袍"NOR, ({ "emperor robe","robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "件");
		set("long","袍色明黄，领袖俱石青片金缘，绣文金九龙，列十二章，间以五色云，领前后正龙各—，左右及交襟处行龙各一，油端正龙各一，下幅八宝立水裙左石开。\n领边缀着一行小字：背影裁制。\n");
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


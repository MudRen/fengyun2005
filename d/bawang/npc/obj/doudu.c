// By clone 6/2001
// cloth.c
// add some funny stuff :P

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIY"五"+HIR"彩"NOR+"小兜肚", ({ "doudu" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件五彩丝编成的小兜肚，恶虎岗的年轻女强盗们穿来晒日光浴用的。
据考证，这就是现代三点式泳装的鼻祖。\n");
		set("material", "cloth");
		set("value", 100);
		set("armor_prop/armor", 3);
	}
	::init_cloth();
}

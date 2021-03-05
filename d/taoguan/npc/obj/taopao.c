// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("云纹道袍", ({ "taopao","cloth" }) );
	set_weight(1000);
	set("long", "一件绣满云纹的道袍，衣袖上绣着“阳明江”几个小字。\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("value", 1000);
	}
	::init_cloth();
}

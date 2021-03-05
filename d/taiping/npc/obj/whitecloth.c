#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("白色庄服", ({ "white cloth","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","一件白色的长袍，上面绣着一个小小的“李”字。");
		set("material", "cloth");
		set("armor_prop/armor", 10);
		set("value",1000);
	}
	::init_cloth();
}

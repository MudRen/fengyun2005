#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("红纱裙", ({ "red cloth","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件漂亮的小红纱裙，奇怪的是只有左边半截。");
		set("material", "cloth");
		set("armor_prop/armor", 20);
	}
	::init_cloth();
}

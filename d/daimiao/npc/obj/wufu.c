#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
	set_name(HIW"白羽袍"NOR, ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long","一件雪白的长袍，边缘镶饰着羽毛。\n");
		set("material", "cloth");
		set("armor_prop/armor", 20);
	}
	::init_cloth();
}

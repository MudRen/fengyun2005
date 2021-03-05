#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
	set_name("破旧锦衣", ({ "cloth"}) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "vine");
		set("long", "一件丝做的华丽的锦服，但是已经破旧不堪。\n");
		set("value", 1000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}

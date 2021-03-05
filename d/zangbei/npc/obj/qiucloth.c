#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
	set_name("貂裘", ({ "furcoat", "coat" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("value", 100);
		set("armor_prop/armor", 5);
		set("long","一袭价值千金的貂裘。\n");
	}
	::init_cloth();
}

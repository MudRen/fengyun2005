#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
	set_name("淡青色的长袍", ({ "cyan robe","robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 10);
		set("long","一件淡青色的长袍，边缘的丝线非常精致。\n");
	}
	::init_cloth();
}

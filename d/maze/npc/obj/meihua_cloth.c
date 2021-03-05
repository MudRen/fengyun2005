#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
	set_name("纱衣", ({ "cloth" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("long","一件纱衣。\n");
	}
	::init_cloth();
}


#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
	set_name("白衣", ({ "cloth" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("long","一件灰白色的衣服，不知道是什么质料，托在手里一点分量没有。\n");
	}
	::init_cloth();
}

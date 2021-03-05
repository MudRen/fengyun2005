#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
	set_name("喇嘛服", ({ "cloth", "robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 10);
		set("long","一件左襟大、右襟小的喇嘛服，右腋下钉有一个纽扣，系着色布做的两条飘带。\n");
	}
	::init_cloth();
}

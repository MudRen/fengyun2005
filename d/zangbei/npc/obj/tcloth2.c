#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
	set_name("斜玛", ({ "tibetan skirt", "skirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "leather");
		set("value", 400);
		set("armor_prop/armor", 10);
		set("long","一种藏语叫“帮典”的围裙，是藏族妇女喜爱的衣物，也是藏族妇女的标志。\n");
	}
	::init_cloth();
}

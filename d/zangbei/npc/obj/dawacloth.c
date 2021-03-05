#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
	set_name(BLK"黑氆氇藏袍"NOR, ({ "tibetan robe", "robe" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "leather");
		set("value", 400);
		set("armor_prop/armor", 10);
		set("long","一件厚重粗笨，凝满风沙油垢的黑氆氇藏袍。\n");
	}
	::init_cloth();
}

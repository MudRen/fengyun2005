#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create() {
	set_name(HIR"大红斗篷"NOR, ({ "red cloak", "cloak" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "leather");
		set("value", 400);
		set("armor_prop/armor", 10);
		set("long","一件鲜红的，女孩子穿的斗篷。\n");
	}
	::init_surcoat();
}

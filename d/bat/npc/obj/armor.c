#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create() {
	set_name( HIY"金丝软甲"NOR, ({ "armor" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "leather");
		set("value", 1000);
		set("armor_prop/armor", 20);
		set("strength",30);
		set("long","这是一件似金非金、似衣非衣的软甲，暗暗的放出动人的金色光芒，
一看就是天下奇珍。\n");
	}
	::init_cloth();
}

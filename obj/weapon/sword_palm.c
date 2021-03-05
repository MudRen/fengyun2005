#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( HIY"手剑"NOR, ({ "palmsword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "以手为剑.以气御剑.伤人于七尺之外.\n");
		set("value", 0);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_burn", 1);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N的手蹴然伸出，竟然有"+HIY"金"+HIW"石"NOR+"的光芒。\n");
		set("unwield_msg", "$N手上的光芒淡了下去。\n");
	}
	::init_sword(100);
}

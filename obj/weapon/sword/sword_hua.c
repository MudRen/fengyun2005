#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create() {
	set_name( "七修剑", ({ "qixiu sword","sword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "据传该剑既出，能幻出道道金白之光，光到之处，杀伤力极强。\n");
		set("value", 3000);
		set("timbre",40);
		set("level_required",100);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N从宝玉剑鞘中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的宝玉剑鞘。\n");
	}
	::init_sword(70);
}


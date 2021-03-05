#include <weapon.h>
#include <ansi.h>

inherit FIST;
void create()
{
	set_name(CYN"巫师铁掌"NOR, ({ "claw"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("long", "一把奇異的爪子，爪上泛著青光好像淬有劇毒。爪尖裝有倒勾，讓人相信不論
抓著什麼都可以讓它四分五裂。\n");
		set("value", 50);
		set("material", "steel");
		set("experience",5000000);
	}
	init_fist(100);

	set("wield_msg", "$N双手一抖，掌上泛出幽幽的蓝光。\n");
	set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");

}


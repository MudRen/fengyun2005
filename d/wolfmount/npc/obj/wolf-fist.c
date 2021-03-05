#include <weapon.h>
#include <ansi.h>

inherit FIST;
void create()
{
	set_name(HIB"穿心抓"NOR, ({ "shred claw","claw" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("long", "一把奇異的爪子，爪上泛著青光好像淬有劇毒。爪尖裝有倒勾，讓人相信不論
抓著什麼都可以讓它四分五裂。\n");
		set("value", 50);
		set("weapon_prop/spirituality",5);
		set("material", "steel");
		set("level_required",100);
	}
	init_fist(100);
	set("wield_msg", "$N双手一抖，掌上泛出幽幽的蓝光。\n");
	set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");

}

int query_autoload() { return 1; }
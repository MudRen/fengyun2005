// ; annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
#include <combat.h>
inherit BLADE;

void create() {
	set_name(CYN"美刀"NOR, ({ "dollar" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("value", 0);
		set("material", "paper");
		set("long", "这是一张花花绿绿的纸张，纸上印着海珊与拉宾的头像，写着一个＂１０＂字，怎么也不像把刀。\n");
		set("wield_msg", "$N抽出一张$n，迎着风晃了一晃，喇喇作响。\n");
		set("unequip_msg", "$N将一张$n塞到腰包里。\n");
		set("real_usdollar",random(2));	// 1/2机会假钞,escape
	}
	::init_blade(1);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	victim->set_temp("counter_action",1);
	victim->set_temp("counter_msg",CYN"$N看见美刀，飞扑上来抢夺，一边大叫道：我的，我的！\n"NOR);
	// snicker
	return 0;
}

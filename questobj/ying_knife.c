// Copyright C apstone, inc.
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
void create()
{
	set_name(HIC "英吉沙快刀" NOR, ({ "sharp dagger","dagger" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 500);
		set("material", "iron");
	        set("long", @LONG
英吉沙小刀是以原产地英吉沙县而命名的，是新疆少数民族的传统手工工
艺品之一。每一个人身上都有一把，而木拉提也一样拥有一把锋利的英吉
沙小刀。英吉沙小刀出产在芒辛乡兰干村，传说很久以前芒辛乡兰干村里
有一个铁匠可以做出削铁如泥的刀子，很多人从不同地方前来购买，这样
英吉沙小刀就出了名。木拉提在芒辛乡兰干村出身，他的祖父就是那个做
出英吉沙小刀的铁匠，他手上的英吉沙快刀就是他祖父做给他的。一把小
小的刀，记载了木拉提祖父的成功。
LONG);
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入靴子里。\n");
	}
	::init_dagger(20);
}

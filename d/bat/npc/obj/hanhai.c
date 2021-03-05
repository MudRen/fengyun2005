// blade.c

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(MAG"瀚海云烟"NOR, ({ "yunblade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
            	set("long", "这是一把银光雪亮的长刀，刀刃间隐隐有血光流动，
锋利无匹，映面生寒。\n");
//		set("value", 0);
		set("material", "iron");
		set("agility",30);
		set("wield_msg", "只听「铮」的一声，瀚海云烟脱鞘飞出，自行跃入$N
掌中。瞬时天际间风云变色，电闪雷鸣，弥漫着一片无边杀意。\n");
        	set("unwield_msg", "瀚海云烟如有灵性，唰的一声飞回鞘内。\n");
	}
	::init_blade(1);
}

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIR"九环大砍刀"NOR, ({ "nine-ring blade","blade" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 1000);
		set("material", "iron");
		set("long", "这是一柄长柄厚背大砍刀，刀背上九孔，每孔穿一环。份量大约六、七
十斤重。\n");
		set("wield_msg", "“哗呤呤”一响，$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n别在背后。\n");
	}
	::init_blade(15);
}

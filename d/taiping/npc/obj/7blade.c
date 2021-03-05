#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIG"七星宝刀"NOR, ({ "blade" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
        	set("value", 500);
		set("class","bat");
	     	set("level_required",105);
		set("material", "iron");
        	set("long", "这是海龙王在年轻时杀人越货所用的宝刀。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
    init_blade(80);
}

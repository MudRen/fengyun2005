#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
	set_name(HIY"赤金盘琉璃圈"NOR, ({ "dragonlace"}) );
	set_weight(15);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个赤金盘琉璃圈,具有名门风范，平添一分娇人姿态。\n");
		set("unit", "个");
		set("value", 500000);
		set("wear_msg", "$N轻轻地把一个$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");
		set("female_only", 1);
        }
        ::init_neck();
}


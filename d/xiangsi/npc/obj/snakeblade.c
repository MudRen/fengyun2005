#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(MAG"烟锁残霞"NOR, ({ "twilight blade","blade"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "柄");
		set("long", MAG"一柄淡紫色的弯刀，刀身上刻着一条昂首吐信的小蛇。\n"NOR);
		set("material", "iron");
		set("value",10);
		set("lore", 1);
	}
	::init_blade(10);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	return MAG"烟锁残霞上泛出层层紫云，将$n"MAG"笼罩其中。\n"NOR;
}

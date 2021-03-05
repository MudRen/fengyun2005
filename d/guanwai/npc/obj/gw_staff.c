
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("飞龙棒" , ({ "staff" }) );
	set_weight(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条又粗又长的精钢杖，上面镶著几条龙。\n");
        set("value", 600000);
		set("rigidity", 50);
		set("material", "iron");
		set("wield_msg", "$N拿出一根闪亮的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	::init_staff(25);
}

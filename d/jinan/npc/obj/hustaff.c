
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
    set_name("虎尾三截棍" , ({ "tiger staff", "staff" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "根");
       set("long", "这是一把由三截棍连成的兵刃，上雕飞虎九头以示威严。\n");
        set("value", 5000);
		set("material", "wood");
        set("wield_msg", "$N抽出一根的$n紧紧握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

    ::init_staff(10);
}

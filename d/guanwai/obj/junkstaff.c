
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("木禅杖" , ({ "wood staff", "staff" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条脏兮兮的木禅杖，上面还有狗咬过的痕迹。\n");
		set("value", 5);
		set("material", "wood");
		set("wield_msg", "$N拿出一根脏兮兮的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	::init_staff(10);
}

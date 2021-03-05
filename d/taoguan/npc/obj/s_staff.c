#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("哭丧棍" , ({ "staff" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条黑黝黝的木杖，上面还挂着几张纸钱。\n");
		set("value", 2000);
		set("rigidity", 50);
		set("material", "iron");
		set("wield_msg", "$N拿出一根$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	::init_staff(10);
}

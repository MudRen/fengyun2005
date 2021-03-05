
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("九环禅杖" , ({ "9-ring staff", "staff" }) );
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条又粗又长的寒铁禅杖，上面镶著九个金环。\n");
		set("value", 600);
		set("material", "iron");
		set("wield_msg", "$N拿出一根乌黑的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	::init_staff(30);
}

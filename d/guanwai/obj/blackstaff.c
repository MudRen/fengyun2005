#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("黑木禅杖" , ({ "black staff", "staff" }) );
	set_weight(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条黑色的禅杖，是历代活佛的信物。\n");
		set("value", 20);
		set("rigidity", 50);
		set("material", "iron");
		set("wield_msg", "$N拿出一根乌黑的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	::init_staff(10);
}

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("法杖" , ({ "scepter"}) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是都松钦巴活佛生前讲经时手中所拿的短杖，珍贵无比。\n");
		set("value", 0);
		set("rigidity", 50);
		set("material", "iron");
		set("wield_msg", "$N拿出一根黄灿灿的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	::init_staff(7);
}



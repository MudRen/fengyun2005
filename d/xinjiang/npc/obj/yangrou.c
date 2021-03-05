#include <weapon.h>
inherit THROWING;
inherit F_FOOD;
void create()
{
	set_name("烤羊肉串", ({ "fried sheep meat", "sheep", "meat" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一串烤得又香又热又辣的羊肉串！好吃啊！\n");
		set("unit", "把");
                set("base_unit", "串");
                set("base_weight", 40);
                set("base_value", 25);
		set("food_remaining", 4);
		set("food_supply", 40);
		set("wield_msg", "$N抓起一根$n，握在手中。\n");
		set("material", "bamboo");
	}
	set_amount(1);
	::init_throwing(1);
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
	set_name("插羊肉串的竹条", ({ "bamboo stick" }) );
	set_weight(150);
	set("long", "一根用来插羊肉串的竹条\n");
	return 1;
}

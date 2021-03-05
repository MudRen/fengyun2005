// chicken_leg.c
#include <weapon.h>
inherit HAMMER;
inherit F_FOOD;

void create()
{
	set_name("香喷喷的大火鸡", ({ "fried turkey", "turkey"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一只烤得香喷喷的大火鸡，风云全体巫师祝贺大家感恩节快乐！！\n");
		set("unit", "只");
		set("food_remaining", 40);
		set("value",1);
		set("food_supply", 20);
		set("wield_msg", "$N抓起一只$n，握在手中当武器。\n");
	}
        ::init_hammer(100);

}

int finish_eat()
{
	object money;
        if( !query("weapon_prop") ) return 0;
        set_name("啃得精光的火鸡骨", ({ "bone" }) );
        set_weight(150);
        set("long", "一根泛着金光的火鸡骨\n");
	set_max_encumbrance(100);
	money = new("/obj/money/gold");
	money->move(this_object());
        return 1;
}

int is_container()
{
        if(this_object()->query("name") == "啃得精光的火鸡骨" )
                        return 1;
        else  return 0;
}


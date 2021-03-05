inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("小蘑菇", ({ "mushroom" , "小蘑菇"}) );
    set_weight(30);
    if( clonep() )
    	set_default_object(__FILE__);
    else {
        set("unit", "些");
        set("long", "一些粉色的小蘑菇。 \n");
        set("value", 1);
        set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");         
    }
	::init_item();
}

/*
int finish_eat()
{
	object me;
	
	me = this_player();
	me->apply_condition("mushroom", 1+random(6));
}

*/
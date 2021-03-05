inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("蘑菇", ({ "mushroom" , "蘑菇"}) );
    set_weight(10);
    if( clonep() )
    	set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("long", "一个上面带着红色斑点的蘑菇。 \n");
        set("value", 1);
        set("food_remaining", 3);
		set("food_supply", 0);
		set("material", "food");         
    }
	::init_item();
}

int finish_eat()
{
	object me;
	
	me = this_player();
	me->apply_condition("mushroom", 2+random(6));
}


inherit F_FOOD;
inherit ITEM;

void create()
{
    set_name("牛肉干", ({ "beef meat","meat"}) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long", "一块美味的牛肉干,看上去很耐吃的样子.\n");
		set("unit", "块");
//        set("value", 1000);
        set("food_remaining", 4000);
		set("food_supply", 1000);
		set("material", "food");
	}
	::init_item();
}

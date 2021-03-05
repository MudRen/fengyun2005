inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("狼肉脯", ({ "wolfmeat" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "生野狼肉脯，似乎是鹰的可口食物！ \n");
		set("unit", "斤");
		set("value", 60);
        	set("food_remaining", 6);
		set("food_supply", 90);
        	set("material", "meat");
        	set("hawk_food",1);
	}
        ::init_item();
}


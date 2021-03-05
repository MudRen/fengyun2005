inherit ITEM;
inherit F_FOOD;

void create()
{
	int i;
	set_name("红烧肉", ({ "meat" }) );
    	set_weight(500);
    if( clonep() )
	    set_default_object(__FILE__);
    else {
        set("long", "一块香喷喷，油光光的红烧肉。\n");
        set("unit", "块");
        set("value", 150);
        set("food_remaining", 3);
        set("food_supply", 10);
    }
    ::init_item();
}


inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("葱花", ({ "scallion" }) );
    set_weight(1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "干干净净的葱花。\n");
        set("unit", "些");
        set("value", 5);
        set("food_remaining", 1);
        set("food_supply", 10);
    }
    ::init_item();
}


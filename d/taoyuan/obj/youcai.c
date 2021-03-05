inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("小油菜", ({ "you cai", "veg" }) );
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一把绿绿的小油菜。\n");
        set("unit", "把");
        set("value", 10);
        set("food_remaining", 4);
        set("food_supply", 15);
    }
    ::init_item();
}


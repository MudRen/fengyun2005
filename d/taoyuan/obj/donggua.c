inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("冬瓜", ({ "dong gua", "veg" }) );
    set_weight(2000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一个挂着白霜的冬瓜。\n");
        set("unit", "个");
        set("value", 25);
        set("food_remaining", 5);
        set("food_supply", 25);
    }
    ::init_item();
}


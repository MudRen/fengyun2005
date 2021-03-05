inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("带荚毛豆", ({ "soy beans", "maodou" }) );
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "嫩嫩绿绿的小毛豆。\n");
        set("unit", "些");
        set("value", 10);
        set("food_remaining", 3);
        set("food_supply", 15);
    }
    ::init_item();
}


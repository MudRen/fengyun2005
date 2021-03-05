inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("小葱", ({ "xiao cong", "" }) );
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一把水灵灵的小葱。\n");
        set("unit", "把");
        set("value", 10);
        set("food_remaining", 2);
        set("food_supply", 15);
    }
    ::init_item();
}


inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("异果", ({ "yiguo"}) );
    set_weight(50);
    if( clonep() )
        set_default_object(__FILE__);
    else {
    set("prep", "on");
        set("unit", "个");
        set("long", "一种你从未见过的奇异果子。\n");
        set("value", 1);
    set("food_remaining", 1);
    set("food_supply", 16);
    }
    ::init_item();
}  

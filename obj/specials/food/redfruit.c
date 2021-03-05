// TIE @ FY3

inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("奇异的红色果实", ({ "red fruit" }) );
    set_weight(8000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一个红色的果子，散发着淡淡的清香\n");
        set("unit", "个");
        set("value", 1);
        set("food_remaining", 3);
        set("food_supply", 300);
    }
    ::init_item();
}



inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("葱油饼", ({ "bing" }) );
    set_weight(50);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一个香喷喷、热腾腾的葱油饼\n");
        set("unit", "个");
        set("value", 150);
        set("food_remaining", 3);
        set("food_supply", 60);
    }
    ::init_item();
}



inherit ITEM;
inherit F_FOOD;

void create()
{
    set_name("水蜜桃", ({ "taozi", "peach" }) );
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "白中透红的大水蜜桃，好诱人哟。\n");
        set("unit", "个");
        set("value", 20);
        set("food_remaining", 2);
        set("food_supply", 10);
    }
    ::init_item();
}
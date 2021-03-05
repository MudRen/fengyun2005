// TIE @ FY3

inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("超级大南瓜", ({ "pumpkin" }) );
    set_weight(800);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "一个圆圆的，硬邦邦的超级大南瓜！\n");
        set("unit", "个");
        set("value", 15);
		set("food_remaining", 100);
		set("food_supply", 100);
    }
    ::init_item();
}

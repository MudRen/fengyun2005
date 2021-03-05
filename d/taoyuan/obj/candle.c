inherit ITEM;

void create()
{
    set_name("蜡烛", ({ "candle" , "蜡烛"}) );
    set_weight(1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("long", "一个点了一半的蜡烛。\n");
        set("value", 100);
    }
    ::init_item();
}


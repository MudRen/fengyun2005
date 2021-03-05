inherit ITEM;

void create()
{
    set_name("黑色火药", ({ "powder" }) );
    set_weight(5000);
    set("explosive",1);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit","桶");
        set("long", "一桶极为猛烈的火药。\n");
        set("value", 1);
    }
    ::init_item();
}
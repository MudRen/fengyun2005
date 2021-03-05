inherit ITEM;

void create()
{
    set_name("鱼骨头", ({ "fish bone" , "鱼骨头"}) );
    set("marks/catfood",1);
    set_weight(20);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("long", "一个被吃的干干净净的鱼骨头。 \n");
        set("value", 0);
    }
    ::init_item();
}



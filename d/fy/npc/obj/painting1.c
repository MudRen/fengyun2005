inherit ITEM;

void create()
{
        set_name("《苍崖落雪图》", ({ "painting"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "幅");
                set("long", "一幅描绘精致的《苍崖落雪图》，只是没有印方，应是临摹之作。\n");
                set("value", 10000);
        }
        ::init_item();
}



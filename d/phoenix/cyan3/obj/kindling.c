inherit ITEM;

void create()
{
    set_name("火种", ({ "kindling" }) );
    set_weight(5);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("long", "一份小小的火种。\n");
        set("value", 0);
    }
    ::init_item();
}

void init()
{
       add_action("do_light", "use");
}

int do_light(string arg)
{
        if( arg != "kindling" ) return 0;

        tell_object(this_player(),"你掏出一个" + this_object()->name() + "打了几下。\n");
        environment(this_player())->light_notify(this_object(), 0);
        environment(this_player())->kindling_notify(this_object(), 0);

        return 1;
}



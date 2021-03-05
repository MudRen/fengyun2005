inherit ITEM;

void create()
{
    set_name("火摺子", ({ "lighter" , "火摺子", "huozhizi"}) );
    set_weight(5);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("lighter",1);
        set("long", "一个可以用来点火的火摺子。\n");
        set("value", 20);
    }
    ::init_item();
}

void init()
{
        add_action("do_light", "use");
}

int do_light(string arg)
{
        if( arg != "lighter" ) return 0;

        tell_object(this_player(),"你掏出一个" + this_object()->name() + "打了几下。\n");
        environment(this_player())->light_notify(this_object(), 0);

        return 1;
}



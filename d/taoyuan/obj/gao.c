// 
inherit ITEM;

void create()
{
    set_name("铁镐",({ "gao", "mattock", "tie gao" }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "把");
    set("value",1);
        set("material", "steel");
        set("long", "一把约三尺多长的铁镐，可以用来挖掘（dig）。\n");
    }
    ::init_item();
}

void init()
{
        add_action("do_dig", "dig");
}

int do_dig(string arg)
{

        message_vision("$N拿出一把" + this_object()->name() + "。\n", this_player() );
        environment(this_player())->dig_notify(this_object(), 0);

        return 1;
}

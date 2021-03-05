// pipe.c

inherit ITEM;

void create()
{
        set_name("圣笛",({ "saint pipe","pipe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "steel");
                set("long", "一根笛子，不知道是用什么动物的角做成的。\n");
        }
	::init_item();
}

void init()
{
        add_action("do_blow", "blow");
}

int do_blow(string arg)
{
        if( arg != "pipe" ) return 0;

        message_vision("$N拿起一个" + this_object()->name() + "吹了一声。\n", this_player() );
        environment(this_player())->pipe_notify();

        return 1;
}

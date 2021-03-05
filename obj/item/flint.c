inherit ITEM;

void create()
{
    	set_name("燧石", ({ "flint"}) );
    	set_weight(5);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("unit", "块");
        	set("long", "一块旅行者用来点篝火的燧石。\n");
        	set("value", 10000);
    	}
    	::init_item();
}

void init()
{
        add_action("do_light", "use");
}


int do_light(string arg)
{
        if( arg != "flint" ) return 0;

        tell_object(this_player(),"你掏出一块" + this_object()->name() + "打了几下。\n");
        environment(this_player())->light_notify(this_object(), 0);
        return 1;
}

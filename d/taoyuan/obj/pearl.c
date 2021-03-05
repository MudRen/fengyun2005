inherit ITEM;

void create()
{
	set_name("夜明珠", ({ "pearl" , "夜明珠"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个在黑夜闪闪发光的夜明珠。\n");
		set("value", 1000);
	}
    ::init_item();
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        if( arg != "pearl" ) return 0;

        tell_object(this_player(),"你掏出一个" + this_object()->name() + "。\n");
        environment(this_player())->light_notify(this_object(), 1);

        return 1;
}



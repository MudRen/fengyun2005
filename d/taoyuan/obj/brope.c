
inherit ITEM;

void create()
{
    	set_name("藤萝绳", ({ "rope" }) );
    	set_weight(10000);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("unit", "条");
        	set("long", "紫色的藤萝绳还泛着油油的光泽，你也许可以用它来拴住什么（ｔｉｅ）。\n");
        	set("value", 0);
    	}
    	::init_item();
}

void init() {
	
	add_action("do_use", "tie");
}

int do_use(string arg)
{
        tell_object(this_player(),"你掏出一条" + this_object()->name() + "。\n");
	if (!environment(this_player())->tie_notify(this_object()))
		return notify_fail("你四处看了看，这儿没什么地方可以用来拴住绳子。\n");
	destruct(this_object());
        return 1;
}

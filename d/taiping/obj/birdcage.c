inherit ITEM;
void create()
{
	set_name("旧鸟笼", ({ "birdcage"}) );
	set_weight(500);
	set_max_encumbrance(1000);
	set("closed",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个宝塔型的旧鸟笼，已经破烂的没法养鸟了。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

void init()
{
	if(this_player()==environment())
		add_action("do_open","open");
}

int do_open(string arg)
{
	object	me, ob;
        if( !arg || arg != "birdcage" )
                return notify_fail("你要打开什么？\n");
	else
		return notify_fail("这个破鸟笼，开着和关着没什么区别。\n");
}

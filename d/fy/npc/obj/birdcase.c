inherit ITEM;

void create()
{
	set_name("精致鸟笼", ({ "birdcase"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("contains",1);
	set("skylark",0);
	set("closed",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个精致的小鸟笼，呈方形，一端有向上抽(open)的门。\n");
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
        if( !arg || arg != "birdcase" )
                return notify_fail("你要打开什么？\n");
	else
		return notify_fail("现在又没有鸟装，先抓只鸟再说吧？\n");
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}

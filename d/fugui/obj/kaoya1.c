inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("烤鸭", ({ "fried duck","duck" }) );
	set_weight(80);
	set_max_encumbrance(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一只香喷喷的烤鸭，鼓鼓囊囊的里边似乎有东西（cut）。\n");
		set("unit", "只");
        	set("closed", 1);
		set("value", 0);
		set("food_remaining", 3);
		set("food_supply", 100);
	}
	::init_item();
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","cut");
}
int do_open(string arg)
{
	object me, ob;
        if( !arg ||( arg != "duck" && arg != "fried duck") )
                return notify_fail("你要割开什么？\n");
	me = this_player();
	ob = this_object();
	if(ob->query("closed") == 1)
	{
		message_vision("$N用刀小心地将$n切开．．．。\n", me, ob);
		ob->set("long", "一只香喷喷的烤鸭，已经被切开，正在流着油。\n");
		ob->set("closed",0);
     	  	return 1;
	}
	else
	{
		message_vision("$N已经被切开了．．．。\n", ob);
	       	return 1;
       	}
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}

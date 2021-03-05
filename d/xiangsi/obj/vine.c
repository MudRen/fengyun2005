// annie. 07.2003
// dancing_faery@hotmail.com

inherit ITEM;

void create()
{
	set_name("藤蔓", ({ "vine", "藤蔓" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","inside");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "片");
	    set("long", "茂密的藤蔓覆盖了整片的崖壁。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


void init()
{
	add_action("do_climb", "climb");
}


int do_climb(string arg)
{
	object me;
	me = this_player();
	if (arg == "cliff" || arg == "山壁")
		return notify_fail("山壁对你来说太高了，怎么都爬不上去呀。\n");
		
	if(arg != "藤蔓" && arg != "vine")
		return notify_fail("你要爬什么？\n");
	
	if (me->is_fighting() || me->is_busy())
		return notify_fail("你现在正忙。\n");
	
	message_vision("$N抓住藤蔓，慢慢的向山壁上攀登而去。\n",me);
	me->move(load_object("/d/xiangsi/shipai"));
	me->perform_busy(1);
	message("vision",me->name()+"从山下慢慢的爬了上来。",environment(me),me);
	return 1;
}


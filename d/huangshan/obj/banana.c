inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("大香蕉", ({ "banana", "xiang jiao" }) );
        set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long", "好大的香蕉啊！一定非常好吃。快把它剥开。（ＰＥＥＬ）\n");
        set("unit", "个"); 
        set("food_remaining", 4);
        set("food_supply", 10);
        set("value", 80);
        set("peeled", 1);
    }
	::init_item();
}

void init () {
	if(this_player()==environment()) {
		add_action("do_peel", "peel");
		add_action("do_eat", "eat");
	}
}

int do_peel(string arg)
{
	object banana, me;
	
	if (!arg || arg != "banana" && arg != "大香蕉" && arg != "香蕉") {
		write("你要剥什么？\n");
		return 1;
	}
	me = this_player();
	if(query("peeled")) {
		message_vision("$N迫不及待地剥开了香蕉。\n", me);
		set("long", "剥开皮的香蕉。还看什么啊？快吃吧。\n");
		set("peeled", 0);
		return 1;
	} 
}

int do_eat(string arg)
{
	object banana, me;
	me = this_player();
	
	message_vision("$N把香蕉赛到了嘴里。\n", me);
    me->add("food", 2);
    destruct(this_object());
    return 1;
}

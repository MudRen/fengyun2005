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
        set("value", 80);
        set("skin_remain", 10);
    }
	::init_item();
}

void init () {
	if(this_player()==environment()) {
		add_action("do_peel", "peel");
	}
}

int do_peel(string arg)
{
	object banana, me, weapon, obj;
	
	if (!arg || arg != "banana" && arg != "大香蕉" && arg != "香蕉") {
		write("你要剥什么？\n");
		return 1;
	}
	me = this_player();
	if((int)query("skin_remain") >=1) {
		message("vision", "你迫不及待地剥开了香蕉，吃惊地发现里面竟然又是一层香蕉皮！\n", me);
		message("vision", me->name() + "迫不及待地剥开了香蕉，脸上露出吃惊的颜色。\n",
				environment(me), me);
		add("skin_remain", -1);
	} else {
		tell_object(me, "你剥开了最后一层香蕉，里面什么都没有。你脸上露出不解的神色！\n");
		message("vision", me->name() + "手里拿着香蕉皮，脸上露出不解的神色。\n",
				environment(me), me);
		obj = new(__DIR__"bananaskin");
		obj->move(me);
		destruct(this_object());
	}
	return 1;
}

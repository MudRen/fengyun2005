inherit ITEM;

void create()
{
    set_name("毽子", ({ "jian zi" , "毽子" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个小孩子玩的用五彩羽毛做成的毽子。\n");
		set("marks/toy", 1);
		set("value", 100);
	}
	::init_item();
}

void init() {
	add_action("do_play", "play");
}

int do_play(string arg) {
	object me;
	
	me = this_player();
	
	if(!arg || arg != "jian zi" && arg != "jianzi" && arg != "毽子") return 0;
	if( me->is_busy() ) return notify_fail("你正在忙！\n");
	if( me->is_fighting() ) return 0;
	message_vision("$N嘴里数着，开始踢毽子。五彩羽毛做成的毽子绕着$N翻飞。\n", me);
	me->start_busy(2);
	return 1;	
}




// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("闻香瓶", ({ "bottle"}) );
    set_weight(800);
    if (clonep())
    	set_default_object(__FILE__);
    else {
		set("unit", "个");
		set("long", "一个白中透出绿色的小玉瓶，瓶盖紧闭。\n或许你可以旋开瓶盖，嗅上一嗅(smell)。\n");
		set("value", 1);
        	set("prep", "in");
    		set("value", 5000);
			set("owner","na da");
    }
	::init_item();
}

void init()
{
   	add_action("do_open","smell");
}

int do_open(string arg)
{
	object me, ob, item;
	
	me = this_player();
	ob = this_object();
	if( !arg || (arg != "bottle" && arg != "玉瓶") ) {
		return notify_fail("你要闻什么？\n");
	}
	if (!query("value"))
		return notify_fail("瓶中的香气已经逸散一空了。\n");
	message_vision("$N小心翼翼地把$n盖旋转开．．．\n",me,ob);
	tell_object(me,"一阵醉人的香气沁进你的鼻端。\n");
	if ( REWARD_D->riddle_check(me,"绝世芳华") == 2)
		REWARD_D->riddle_set(me,"绝世芳华",3);
	set("long", "一个白中透出绿色的小玉瓶，瓶盖已经被打开。\n");
	set("no_stack",1);
	set("value",0);
	return 1;
}


#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("红色蜡球", ({"red ball", "redball", "ball"}) );
    set_weight(30);
	set("unit", "个");
	set("long", "一个红颜色的蜡球。你可以试着把它打开(open)\n");
	set("value", 200);
    ::init_item();
}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
}

int do_open(string arg)
{
	object me, ob, medicine, *inv, *players;
	int	str, i;
	
    if( !arg || arg != "红色蜡球" && arg != "red ball" && arg != "redball") 
    	return notify_fail("你要打开什么？\n");
	
	me = this_player();
	ob = this_object();
	str = me->query_str();
	
	if(str > 20) {
		message_vision("$N微一运力，只听一声脆响，蜡丸碎开，一阵药香弥漫了开来。\n", me);
        seteuid(getuid());
		medicine = new(__DIR__"medicine");
		if(objectp(medicine)){
		    medicine->move(me);
		}
		destruct(ob);
	} else {
		message_vision("你用力捏了捏，蜡丸把你的手硌的生痛。\n", this_object(),me);
	}
    return 1;
}


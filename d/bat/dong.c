inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "洞口");
        set("long", @LONG
一块屏风似的岩石后，悬着条钢索，吊着辆滑车(huache)。钢索通向一个黑黝
黝的山洞。 
LONG
        );
        set("exits", ([ 
       "west" : __DIR__"anbian",
	]));
        set("item_desc", ([
                "huache": @TEXT
似乎可以跳(dash)进去,但里面...
TEXT
        ]) );
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",30);
	setup();
}

void init()
{
        add_action("do_dash", "dash");
}

int do_dash(string arg)
{
        object room;
        object me;
        me = this_player();
	
		if (me->is_busy())
			return notify_fail("你现在正忙。\n");
			
		if (!arg || arg == "huache" || arg == "滑车") {
			room = find_object(__DIR__"dong1");
			if (!room) room = load_object(__DIR__"dong1");
			message_vision("$N一下子就跳进了滑车！\n",me);
			tell_object(me,"你越坠越快．．．．你似乎听见了一声惨叫，不禁毛骨悚然。\n");
	       	me->move(room);
        	return 1;
        }
        write("你想往哪儿跳？\n");
        return 1;
}
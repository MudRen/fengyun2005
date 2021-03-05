inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "地狱谷");
        set("long", @LONG
这是一个很阴森的山谷，即使是阳光正烈的中午，山谷中仍然是云雾弥漫。山
谷很陡，终年被雾气笼罩着，不知深浅，自然也不会有人攀越下去了。雾气中蒸腾
一种霉烂的气味，被阳光照着，居然映射出七彩的光辉。这就是所谓的瘴气，含有
毒的，偶尔迷路的樵夫曾经看见有小鸟飞越其上，一不小心沾着一点雾气，立刻就
一头栽落下去。这是一片死亡之谷。
LONG
        );
        set("exits", ([ 
		"southwest":  __DIR__"hellvalley2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1970);
        set("coor/y",630);
        set("coor/z",10);
	set("map","zbwest");
	setup();

}


void init()
{
        add_action("do_dive", "jump");
        add_action("do_dive", "jumpdown");
        add_action("do_dive", "jumpto");
        add_action("do_climb", "climb");
}

int do_dive(string arg)
{
//      object room;
        object me;
        me = this_player();
        call_out("jump_down",6,me);
        me->start_busy(3);
	message_vision(YEL"$N长长吸了口气，一闭眼，向山谷下跳去。\n"NOR,me);
	tell_object(me,YEL"你越坠越快．．．．你似乎听见了一声惨叫，不禁毛骨悚然。\n"NOR);
        return 1;
}

int jump_down(object me)	{
        object room;
        if(!objectp(me)) return 1;
  	if (me->is_ghost()) return 1;
	room=find_object(__DIR__"hellvalley4");
	if(!objectp(room)) 
        	room = load_object(__DIR__"hellvalley4"); 
	tell_object(me,WHT"只听“扑通”一声，你落到了坚实的泥土地上，原来这个山谷一点都不深。\n"NOR);
	me->move(room);
	message("vision","只听“扑通”一声，"+me->name()+"从上面掉了下来。\n"NOR,environment(me),me);
        return 1;
}


int do_climb(string arg)
{
//      object obj;
//      object me,room;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "山" || arg == "mountain" || arg == "down")
        {
		write("这个地方太险，大概爬不下去。\n");
        	return 1;
        }
        else
        {
                write("你不可以这么爬。");
                return 1;
        }
}
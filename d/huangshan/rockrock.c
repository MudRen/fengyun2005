// ; annie 07.2003
// dancing_faery@hotmail.com
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "大黑石上");
        set("long", @LONG
这里是寒潭背后的一块偌大黑石，你费劲力气爬了上来，却发现早已经有人立
在这里。定眼望去，只见那人一身青竹编衣，长发飘飘，正痴痴的吹着叶笛，那满
脸于思，满心怅罔，仿佛就这么在撮唇清吹的哀婉笛声中，吹走了光阴几许，吹白
了少年头．．．
LONG
        );
		set("objects", ([
		__DIR__"npc/du2" : 1,
	]));   
    set("outdoors", "huangshan");
	set("coor/x",-50);
	set("coor/y",50);
	set("coor/z",20);
	setup();
}

void init()
{
    	add_action("do_swim", "swim");
}

int do_swim()
{
	object me, obj;

	me = this_player();
	if (me->is_busy())
		return notify_fail("你现在正忙。\n");
	message_vision("$N一个猛子扎入了水中。\n", me);
	tell_object(me,"忽的一道暗流涌来，将你推过潭中一片茂密水草。\n");
	obj = load_object(__DIR__"pond");
	me->move(obj);
	tell_object(me,"你忙不迭的从水中爬上潭边。\n");
	message("vision", me->name() + "湿漉漉的从水里爬了上来。\n", environment(me), me);
	return 1;
}

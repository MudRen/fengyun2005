// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "储藏室");
        set("long", @LONG
这是焦都驿存放杂货的地方，可是这里只有南瓜。东面的土墙上似乎有很多人
影在晃动。
LONG
        );
        set("exits", ([
                "north" : AREA_QUICKSAND"huangyie1",
        ]) );
	set("NONPC",1);
        set("objects", ([
		__DIR__"npc/obj/pumpkin" : random(10)+1,
		__DIR__"npc/obj/wineskin" : random(10)+1,
        ]) );
        set("item_desc", ([
                "土墙": "一道又破又脏的泥墙，你似乎可以越（ｄａｓｈ）过去。\n",
                "wall" : "一道又破又脏的泥墙，你似乎可以越（ｄａｓｈ）过去。\n"
        ]) );
	set("coor/x",10);
	set("coor/y",30);
	set("coor/z",10);
	setup();
}
void init()
{
	add_action("do_dash","dash");
}
 
int do_dash()
{
object me;
object room1,room2;
	me = this_player();
	room1 = load_object(__DIR__"aihe2");
	room2 = load_object(__DIR__"ghostinn");
	message_vision("$N往土墙上一越就不见了。\n\n",me);
	if(me->query_temp("can_pass_wall"))
	{
		me->move(room1);
		me->delete_temp("can_pass_wall");
	}
	else
		me->move(room2);
	return 1;
}

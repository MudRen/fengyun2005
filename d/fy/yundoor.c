#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIC"云坛"NOR);
    set("long", 
"云坛其实不是什么高坛，只是道旁一个很简单的凉亭，云坛里也从不祭祀天地
神灵，只常常有几个须发皆白的老人在这里喝茶。但大凡初入风云的人，都喜欢到
这里歇息，听老人们讲一些武林逸闻，听一些让人热血沸腾的故事，而这简陋的茶
亭似乎也成了他们赤手空拳打创天地的起点。
"+HIC"
                   云            坛

"NOR
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"swind2",
  		"north" : __DIR__"fysquare",
  		"east" : __DIR__"yitea",
//  		"west" : __DIR__"jiulou",
  		"west" : __DIR__"station",
]));
        set("outdoors", "fengyun");
        set("objects", ([
	        __DIR__"npc/mei": 1,
                        ]) );

	set("coor/x",0);
  set("coor/y",-40);
	set("coor/z",0);
 set("map","fysouth");
	setup();
}

/*
int valid_leave(object me, string dir)
{
	object room;
	if (dir == "west")
	{
		room=find_object("/p/residence/train");
		if (!room)
			room=load_object("/p/residence/train");
		message_vision("$N向下离开。\n"NOR,me);
		tell_object(me,CYN"\n一阵悠扬的音乐在站台中回响，启程的摇铃轻轻晃荡。\n你连忙爬上道列，在一群胖乎乎的怪猫里找了一个座位坐下。\n\n"NOR);
		me->set_temp("annie/laputa_up",1);
		me->set_temp("annie/laputa_down",0);
		me->move(room);
		tell_object(me,HIG"\n道列缓缓的驶出了站台．．．"NOR);
//		message_vision("$N走了过来。\n"NOR,me);
		return notify_fail(" ");
	}
	return 1;
}
*/

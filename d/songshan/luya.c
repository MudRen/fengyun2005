// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "卢崖瀑布");
        set("long", @LONG
景色天成，大自然的妙手是任何能工巧匠难以企及的，瀑布不大，但是在绿树
中透过的那一丝水光，那一抹彩虹却是让疲惫的游人休憩的最好场所，略微有点高
亢的水声激荡着人们的心，和青童峰遥相呼应，是嵩山最没有烟火气息的地方。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"zhongyue", 
  "north" : __DIR__"qingtong",
]));
        set("objects", ([
                __DIR__"npc/wuhua" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",20);
	set("coor/y",12);
	set("coor/z",0);
	setup();
}


int valid_leave(object me, string dir)
{
        object ob;
        if( dir == "north" && ob=present("tian feng 14 lang", this_object()))
		if(!me->query_temp("marks/okey_to_see"))
		{
		ob->do_test(me);
		return notify_fail("");
		}
		return 1;
}


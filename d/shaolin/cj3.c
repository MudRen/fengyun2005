// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "藏经楼");
        set("long", @LONG
专研天下正派武功，各大名门正派的武功这里均有记载，几名老僧正在苦修，
据传每人兼通数艺，即便是那一派掌门，也未必有此功力，想博览这里的书籍，
只有得到几位老僧的垂青。西侧有扇木门，门后楼梯通往四楼。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"cj4",
  "down": __DIR__"cj2",
]));
        set("objects", ([
                __DIR__"npc/monk20c" : 3,
                __DIR__"obj/slayedman2" : 2,
       ]) );
	set("coor/x",0);
	set("coor/y",100);
	set("coor/z",40);
	set("no_lu_letter",1);
	setup();
	create_door("up","door", "木门", "down", DOOR_CLOSED);

}

int valid_leave(object me,string dir)
{
        object ob;
	if(userp(me) && dir == "up" && ob=present("shaolin monk",this_object()))
	{
	message_vision("$N对$n道：藏经楼乃少林禁地,请止步!\n",ob,me);
	return notify_fail("");
	}
	return ::valid_leave(me, dir);
}

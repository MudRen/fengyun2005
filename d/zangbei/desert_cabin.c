inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "守望塞");
        set("long", @LONG
这几间木屋本是昔日巡边戍卒的守望塞，已十分陈旧，有几扇窗子没有关，屋
子里好像已有了灯光，想来屋子里一直都有人的。十数丈外有三棵大树，早已枯死
多年了。[37m木屋[32m里隐约有一阵低迷的乐声传出，婉转销魂，欲仙欲死。
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"desert_cabin2",
		"south" : __DIR__"yangguan1c",
	]));
        set("objects", ([
        	
	]) );
	set("item_desc", ([
		"木屋": "一扇木门通向木屋。\n",
		"cabin": "一扇木门通向木屋。\n",
	]));
	set("outdoors", "zangbei");
        set("coor/x",-90);
        set("coor/y",310);
        set("coor/z",0);
        set("map","zbeast");
	setup();
	create_door("north", "door","木门", "south", DOOR_CLOSED);

}

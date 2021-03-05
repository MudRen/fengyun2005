// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "千僧灶");
        set("long", @LONG
这是煮饭的所在，屋内数口大锅，几个和尚正裸着上身，倒吊在屋梁之上，手
持巨棒，搅拌锅中饭食，少林数千僧众每日食物便从这里烹出，细看梁上僧人，面
对扑面热气，竟然毫无不适，看来又是锤炼武学的好方法。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"fanting",
 "north" : __DIR__"bohuo",  
]));
        set("objects", ([
                __DIR__"obj/wok" : 3,
       ]) );
	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",10);
	setup();
	create_door("east", "door","木门", "west", DOOR_CLOSED);

}

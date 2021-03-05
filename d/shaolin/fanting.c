// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "饭厅");
        set("long", @LONG
一间巨大的屋子，屋内四排长桌，上面放着各类蔬菜，食品，每天晨钟暮鼓之
后，僧人便在这里聚集，享用食物。一般按等级高低依次进食，各桌菜肴不同，可
见等级尊卑之严。向西是灶头。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"neiyuan",
  "west" : __DIR__"qianzao",
]));
        set("objects", ([
                __DIR__"npc/monk9" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",10);
	setup();
	create_door("west", "door","木门", "east", DOOR_CLOSED);

}

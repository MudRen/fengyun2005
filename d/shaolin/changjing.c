// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "藏经阁");
        set("long", @LONG
藏经阁，又名“法堂”，存放佛经和高僧说法场所，历代帝王赠经都藏于此处，
一楼通常是用来说法的场所，越往上佛经便越贵重，寺中主持每年的正月都会在此
讲经说法，普渡众生。有扇木门,门后楼梯通往楼上。
LONG
        );
        set("exits", ([ 
  "northdown" : __DIR__"fangnan",
  "up"	: __DIR__"changjing2",
  "southdown" : __DIR__"yonglu2",
  "eastdown": __DIR__"least",
  "westdown": __DIR__"lwest",
]));
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        create_door("up", "door","木门", "down", DOOR_CLOSED);
}

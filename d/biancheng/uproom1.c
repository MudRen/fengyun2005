#include <room.h>
#include <ansi.h>
inherit DOOR_ROOM;
void create()

{
        set("short", "偏房");
        set("long", @LONG
这儿显然是女子的闺房。房里的陈设并不十分堂皇，但很符合庄主对她的喜爱。
墙上挂着用金银各色丝线绣着狩猎图的帐幔，那绣工可算得是最精致的了。床上铺
着一块同样富丽的绸罩单，四围挂着紫色的短幔。椅子也都有彩色套子，其中一张
特别高，前面放着一个镂花的象牙脚凳。至少有四盏银制的灯架，点着高大的蜡烛，
把全屋子照得通明。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"corridor3",
	]));
        set("objects", ([
		__DIR__"npc/sanniang":	1,
		__DIR__"npc/huzi":	1,
	]) );
        set("coor/x",-15);
        set("coor/y",135);
        set("coor/z",10);
	set("map","zbwest");
	setup();
	create_door("south","door","木门","north",DOOR_CLOSED);
}


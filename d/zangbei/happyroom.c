inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "快活林小屋");
        set("long", @LONG
银色的灯嵌在壁上，柔和的灯光照着桌上精致的瓷器，照着那紫檀木上铺着大
理石的桌子。这里绝没有钱买不到的东西，也绝没有不用钱就可以得到的东西。到
这里来就得准备花钱，没有人能例外。因为这里的主人就是高寄萍高老大。将近二
十年艰苦、贫穷的流浪生活，让她懂得了，世上绝没有任何事比钱更重要。
LONG
        );
        set("exits", ([ 
		"west": __DIR__"bridge",
	]));
        set("objects", ([
        	__DIR__"npc/gao":	1,
        	
	]) );
        set("coor/x",-1660);
        set("coor/y",610);
        set("coor/z",10);
	set("map","zbwest");
	setup();
	create_door("west","door","铁门","east",DOOR_CLOSED);
}

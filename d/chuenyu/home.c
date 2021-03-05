inherit DOOR_ROOM;
#include <room.h>
void create()
{
        set("short", "刘家小房");
        set("long", @LONG
这是一所很破旧的木屋。每当山风吹来，都会发出“吱吱呀呀”的声音。南侧
是一个小小的厨房。木屋的后面是一个精巧的花园，花园里穿来阵阵打闹之声。一
个翠绿的小草坪就在西面。西南面有一条小路。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"smallstorage",
  		"north" : __DIR__"littlegarden",
  		"west" : __DIR__"smallyard",
  		"southwest" : __DIR__"dustyroad3",
		]));

        set("objects", ([
                __DIR__"npc/oldliu" : 1,
        ]) );
	
		set("coor/x",-10);
		set("coor/y",-10);
		set("coor/z",-20);
		setup();
}
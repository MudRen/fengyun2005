// street1.c

#include <room.h>
inherit ROOM;
void create()
{
  set("short","济南大街");
  set("long",@LONG
这是济南城的大街，路上行人络绎不绝，看上去都衣着亮丽，不仅附近一带的
有钱人常来这里，而且连关外的参药商也常来这里。使得威名远拨的丐帮也在这设
下了总堂。此处向北是济南城的城门，出入的人不是春光满面，便是垂头丧气。车
水马龙，好不热闹。
LONG
  );
  set("exits",([
         "north":__DIR__"gate",
         "south":__DIR__"street2",
//		 "east" : __DIR__"casino1",
               ]));
    	set("outdoors", "jinan");
       set("objects", ([
                __DIR__"npc/mimicat" : 1,
       ]) );

	set("coor/x",0);
	set("coor/y",100);
	set("coor/z",0);
	setup();

}


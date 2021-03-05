#include <ansi.h>


inherit ROOM;
void create ()
{
  set ("short", WHT"居民区"NOR);
  set ("long", @LONG
济南城外的那方风水宝地在几年前因为胡乱违章搭建被殷正廉大人下令拆毁，
一众没有了归宿的江湖中人就聚在一起商议，最后以千金请出名工巧匠，又斥万金
在重建的风云城中离天机老人最近之处买下一方土地建起一座盈满了花香的旋盘天
梯，通向他们新的家园。
LONG);
        set("exits", ([ 
  "east" : __DIR__"yundoor",
  "up" : "/p/residence/enterance",
]));
  	set("no_fight",1);
  	set("coor/x",-20);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}

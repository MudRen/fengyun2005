#include <room.h>
inherit ROOM;
void create()
{
  set("short","后院");
  set("long",@LONG
这是一个清净的小院，种着许多花草树木，春日里各种花争奇斗艳的开着，即
使冬天也有傲雪的寒梅，更不用说夏日的茉莉秋日的菊花。院的北面是禅房和耶丈
室。
LONG
  );
  set("exits",([
         "east" :__DIR__"changlang4.c",
         "west" :__DIR__"changlang3.c",
         "north":__DIR__"yezhang.c"
               ]));
   
	set("coor/x",1);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}

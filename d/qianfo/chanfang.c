#include <room.h>
inherit ROOM;
void create()
{
  set("short","禅房");
  set("long",@LONG
这是一个清净幽雅的小屋，是寺庙弟子悟道修行的地方，墙上有禅宗六祖的画
像，自左向右为：一祖达摩，二祖慧可，三祖僧璨，四祖道信，五祖弘忍，六祖慧
能，透过窗户可以看到门前的梅树。
LONG
  );
  set("exits",([
         "northeast":__DIR__"houshan.c",
         "south":__DIR__"changlang3.c",
         "east" : __DIR__"yezhang.c"
               ]));
          set("objects", ([
                __DIR__"npc/bigmonk1" : 1,
                __DIR__"npc/bigmonk2" : 1,
                __DIR__"npc/bigmonk3" : 1,
        		__DIR__"npc/bigmonk4" : 1,
        		__DIR__"npc/bigmonk5" : 1,
        		__DIR__"npc/bigmonk6" : 1,
        		__DIR__"npc/bigmonk7" : 1,
        		__DIR__"npc/bigmonk8" : 1,	
       ]) );
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}

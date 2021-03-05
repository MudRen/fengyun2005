#include <room.h>
inherit DOOR_ROOM;
void create()
{
  set("short","耶丈室");
  set("long",@LONG
簇拥在禅房之间的为历代方丈的居所，兴国禅寺是南宗的嫡传寺庙，始祖神会
是六祖慧能晚年的得意弟子，此后人才辈出，向北有一个小门，没有方丈的允许任
何人不得擅入。
LONG
  );
  	set("exits",([
         "south":__DIR__"houyuan.c",
         "north":__DIR__"mishi1.c",
         "east" :__DIR__"chanfang2.c",
         "west" :__DIR__"chanfang.c"
               ]));
          set("objects", ([
                __DIR__"npc/master" : 1,
       ]) );
 	set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
  	create_door("north","door","石门","south",DOOR_CLOSED);
}

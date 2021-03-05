// Room: dong0
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "山谷口");
        set("long", @LONG
一片辽阔的山谷，四山合抱，苍峰滴翠，一道清溪横流过，水波溶溶，游鱼可
数。沿溪一带，绿柳垂扬，如丝如缕，清溪对岸，半坡繁花间，隐隐现出一栋精舍，
四外花枝环绕，灿若云锦。
LONG
        );

       set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"gu",
  "north" : __DIR__"gu1",
 
]));
     
	set("outdoors","tieflag"); 	    
	set("coor/x",40);
	set("coor/y",-10);
	set("coor/z",35);
	setup();
	replace_program(ROOM);

}


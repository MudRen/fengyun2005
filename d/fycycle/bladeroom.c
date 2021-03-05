#include <room.h>
inherit ROOM;
void create()
{
	set("short", "吴钩霜雪");
	set("long", @LONG
此屋四壁及地面均用洁白的汉白玉铺砌，入目如霜如雪。四壁上竟然浮刻着
各种各样的刀。泼风刀，凤尾刀，三尖两刃刀，大环刀，以及许多叫不出名字的
刀。最引人注目的却是摆在屋子正中的一柄弯弯的白玉石刀。它虽静静地摆在那
里，却发出晶莹的光彩和莫名的夺人之气。
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/bladebook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
	set("no_magic",1);
	set("no_spell",1);
    	setup();
}


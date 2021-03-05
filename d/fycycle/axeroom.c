#include <room.h>
inherit ROOM;
void create()
{
	set("short", "开辟鸿蒙");
	set("long", @LONG
屋中的一切好像都在流动。淡淡的烟气似乎不断从缥缈中上升，黑色的地面
仿佛也是某种凝重而流动的液体。你仔细感触之下，却只有虚无静止的空间和凝
实稳定的地面。分割这两者的，是一柄古拙的开天斧。它嵌在正中的墙壁，似乎
是一劈之下分开了天地阴阳的界线。
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/axebook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    	setup();
}


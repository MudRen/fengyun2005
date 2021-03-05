#include <room.h>
inherit ROOM;
void create()
{
	set("short", "烟雨平生");
	set("long", @LONG
走进这里，你如同走进雨雾之中。在泠泠水声里，你惊讶地发现，竟然有一
道小小的瀑布从顶壁泻流而下，在屋子正中汇成小小的水潭。水潭边，有个芒鞋
竹杖的草人，在雨雾中似行似立，浑然忘我。颇有点 “竹杖芒鞋轻胜马，谁怕？
一蓑烟雨任平生。” 的意境。
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/staffbook" : 1,
                        ]) );
    	set("indoors", "fycycle");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
    	setup();
}


#include <room.h>
inherit ROOM;
void create()
{
	set("short", "快马清秋");
	set("long", @LONG
一走进这屋子，你觉得精神顿时一爽。迎面是幅巨大的壁画，白霜四起，弯
月如钩，一个青衣侠士正在马上扬鞭急驶，好一幅清秋快马图。。
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/whipbook" : 1,
                        ]) );
    	set("indoors", "fengyun");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
	set("no_magic",1);
	set("no_spell",1);
    	setup();
}


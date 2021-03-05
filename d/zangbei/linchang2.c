inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "林场");
        set("long", @LONG
走出白杨树林，眼前不禁一亮，雪峰、森林、草场、溪流、湖泊、瀑布和伐木
人的木屋相映成趣。近处是一排排伐出的木料，堆的有小山般高，远眺，念青贡嘎
日松贡布的三座雪峰尽收眼帘，在过去的漫长岁月里，那儿浸润了无数朝圣者的希
冀和梦想，是他们灵魂的归宿之地。
LONG
        );
        set("exits", ([ 
		"southup" : __DIR__"linchang1",
		"east":  __DIR__"woods2",
	]));
        set("objects", ([
        	__DIR__"obj/stump":	2,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1640);
        set("coor/y",680);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

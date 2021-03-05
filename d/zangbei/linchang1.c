inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "上山路");
        set("long", @LONG
路随山转，景随山变，流水潺潺，林木葱葱。再往前，山势陡峭，奇峰对峙，
峰峦垒嶂，怪石嶙峋，雪峰、森林、草场、溪流、湖泊、瀑布和伐木人的木屋相映
成趣。远眺，念青贡嘎日松贡布的三座雪峰尽收眼帘。
LONG
        );
        set("exits", ([ 
		"southwest" : __DIR__"spring",
		"northdown":  __DIR__"linchang2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1640);
        set("coor/y",660);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}

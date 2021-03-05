inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "地狱谷密林");
        set("long", @LONG
念青贡嘎日松贡布就在眼前，但是你看不到，树枝像一把无边无际的伞，遮住
了阳光，遮住了天空，腐烂潮湿的落叶在脚下发出嘎吱的响声，密密的树枝，藤蔓
和野草不时挡住去路，几乎每走一段路就要停下来歇一歇，空气里有浓重的腥湿气
息在悄悄弥漫。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"diyugu",
		"eastup":  __DIR__"nianqing",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1710);
        set("coor/y",620);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

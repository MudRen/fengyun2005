inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "地狱谷底");
        set("long", @LONG
这地狱谷原来真是个山谷，而且是个离崖不到三丈的山谷！谷地的樽、菇、苔、
草、藤、叶、树冒出的瘴气，聚集于顶上，形成了如同云雾一般的烟气，遮住了谷
底的虚实。更由于这瘴气含有毒性，寻常的飞鸟走兽沾着一点就会栽倒下去，附近
的居民都远远避开，使得这地狱谷有了最佳的天然保护障体。。
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"diyugu",
	]));
        set("objects", ([
        	__DIR__"npc/xie":	1,
        	__DIR__"npc/tianmei":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1800);
        set("coor/y",620);
        set("coor/z",0);
	set("map","zbwest");
	setup();

}

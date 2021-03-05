inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "南侧峰");
        set("long", @LONG
南侧峰名央迈勇，山峰陡峭，线条优美，像少女般娴静端庄，冰清玉洁。山峰
前镶嵌着碧蓝如玉的湖泊和草甸。远看山脚下有高高低低几百座砖塔，其中四角的
白、黄、红、绿四塔格外引人注目，便是著名的塔公寺。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"nianqing",
		"southdown":  __DIR__"temple2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1700);
        set("coor/y",600);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}

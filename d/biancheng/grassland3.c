inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大草原");
        set("long", @LONG
万马堂的地界，自东至西，就算用快马急驰，自清晨出发，也要到黄昏才走得
完全程。远远望过去，一面白色的大旗正在风沙中飞卷。大旗似已远在天边。万马
堂似也远在天边！无边无际的荒原，路是马蹄踏出来的，漫长、笔直，笔直通向那
面大旗。旗下就是万马堂。
LONG
        );
        set("exits", ([ 
		"southwest" : __DIR__"grassland2",
		"east" : __DIR__"grassland4",
		"northwest":	__DIR__"gate",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",100);
        set("coor/y",80);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}

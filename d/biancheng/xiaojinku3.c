inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "闺房");
        set("long", @LONG
竹帘已卷起，一个淡扫蛾眉、不施脂粉的丽人，正手托着香腮，坐在窗口，痴
痴地看着院子。她长得也许并不算太美，但却有双会说话的眼睛，灵巧的嘴。她虽
然只是静静地坐在那里，但却自然地有种醉人的风姿和气质。
LONG
        );
        set("exits", ([ 
	"out": __DIR__"xiaojinku2",
	]));
        set("objects", ([
        	__DIR__"npc/cuinong":	1,
	]) );
        set("coor/x",-40);
        set("coor/y",-20);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}

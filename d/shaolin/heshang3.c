// TIE@FY3 ALL RIGHTS RESERVED
inherit DOOR_ROOM;
#include <room.h>

void create()
{
        set("short", "和尚部");
        set("long", @LONG
这是和尚起居的场所。屋子很长，并排放着两排长木床，上面是薄薄的竹席和
一床薄被。禅宗教旨首要便在修行二字，所以禅宗弟子无不时刻着意修行。加上都
修习武艺，所以即便严冬，也就如此安寝。
LONG
        );
        set("exits", ([ 
 "south" : __DIR__"heshang2",  
]));
        set("objects", ([
                __DIR__"obj/buobei" : 1,
		__DIR__"obj/zhuxi" : 1,
			__DIR__"npc/monk20b2" : 1,
       	__DIR__"npc/monk20c2" : 1,
       ]) );
		set("coor/x",10);
		set("coor/y",60);
		set("coor/z",10);
		setup();
		create_door("south", "door","木门", "north", DOOR_CLOSED);
}

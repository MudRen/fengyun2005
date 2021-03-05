// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "和尚部");
        set("long", @LONG
这是和尚起居的场所。屋子很长，有南北两间，并排放着两排长木床，上面是
薄薄的竹席和一床薄被。禅宗教旨首要便在修行二字，所以禅宗弟子无不时刻着意
修行。加上都修习武艺，所以即便严冬，也就如此安寝。
LONG
        );
        set("exits", ([ 
 "east" : __DIR__"neiyuan2",  
 "north" : __DIR__"heshang4",
]));
        set("objects", ([
                __DIR__"obj/buobei" : 1,
                __DIR__"obj/zhuxi" : 1,
                __DIR__"npc/laomonk3" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",50);
	set("coor/z",10);
	setup();
 create_door("north", "door","木门", "south", DOOR_CLOSED);
}


inherit ROOM;
#include <room.h>
void create()
{
        set("short", "走廊");
        set("long", @LONG
一人多高，只容两人并行的檀香木走廊，廊中的两侧陈列着一些奇花异草。滚滚
热气从走廊的一头冒出，将檀木地板打得又湿又滑，你几乎要扶着栏杆才不会滑倒。
LONG
        );
        set("exits", ([
                "east" : __DIR__"jlonglang2",
		"west" : __DIR__"jlongpool",
        ]));
        set("coor/x",-30);
        set("coor/y",40);
        set("coor/z",-300);
        setup();
        create_door("west", "檀木门", "east", DOOR_CLOSED);

}



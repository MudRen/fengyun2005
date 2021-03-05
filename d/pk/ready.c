// Room: /d/pk/ready.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "屠人场休息室");
	set("long", @LONG
这里黑乎乎的，地上还有一些粘满了血迹的布条，偶然也看得到断
了的长剑、钢刀什么的。北面的门紧紧的锁着，里面散发出一阵阵血腥
的气味。
LONG
	);
	set("exits", ([
		"south" : __DIR__"entry",
	]));

        set("no_fight", 1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "south")
                message_vision("$N溜出了休息室。\n", me);
        return 1;
}

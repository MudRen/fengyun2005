inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "木屋");
        set("long", @LONG
这是一幢三间连在一起的棚屋，它矮得几乎站着就已快触到屋檐。看得出，由于
太陈旧，它象个驼背的衰弱老人，随时都有倒塌的危险。门板已烂掉几块。泥墙上的
两个小窗户堵满破席乱草。中间的堂屋的床上躺着个人，不时发出压抑不住的呻吟声。
LONG
        );
        set("exits", ([ 
	"east": __DIR__"smallroad3",
	]));
        set("objects", ([
        	__DIR__"npc/sickwoman": 1,
		__DIR__"npc/sickman":	1,
	]) );
	set("coor/x",-60);
        set("coor/y",-30);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}

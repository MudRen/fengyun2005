inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "山道");
	set("long", @LONG
这是一条通往富贵山庄的崎岖山道。道旁半枯的秋草在夕阳下看来宛如黄金，
遍地的黄金石板砌成的小径斜向上方伸展，宛如黄金堆中的一串白玉，往东望去，
似乎有间供路人歇息的八角小亭。
LONG);

	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
        "westup":__DIR__"shandao4",
        "southdown":__DIR__"shandao6",
	]) );
	set("coor/x",10);
	set("coor/y",150);
	set("coor/z",40);
	setup();
	replace_program(ROOM);
}

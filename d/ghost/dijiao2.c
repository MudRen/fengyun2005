inherit ROOM;

void create()
{
	set("short", "地窖");
	set("long", @LONG
你昏头昏脑地睁开眼睛，这儿已经不是花寡妇的那间小屋了，自然你也不在温
柔乡中。环顾四周，寒冷而潮湿，泥土的墙壁上挂着一盏油灯。昏暗的灯光下，把
这里照得阴森可怖。这可能是哪间屋子下面的一个地窖。
LONG
	);
	set("exits", ([
                "up" : __DIR__"dijiao",
	]));
	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);

}

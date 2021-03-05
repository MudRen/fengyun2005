
inherit ROOM;

void create()
{
        set("short", "黑石道路");
        set("long", @LONG
这是一条以黑石铺成的道路，道路弯曲地穿入一片暗林！入林越深，光线越是
阴暗，但林梢却透下一道天光，照在地上的黑石上，衬得四下更宛如地狱。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"intersection",
  "south" : __DIR__"black2",
]));
        set("outdoors", "palace");

	set("coor/x",-90);
	set("coor/y",90);
	set("coor/z",10);
	set("coor/x",-90);
	set("coor/y",90);
	set("coor/z",10);
	set("coor/x",-90);
	set("coor/y",90);
	set("coor/z",10);
	set("coor/x",-90);
	set("coor/y",90);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}



inherit ROOM;

void create()
{
        set("short", "精舍前");
        set("long", @LONG
穿过路旁的草地，四下观望，只见路边一栋精舍，建筑在翠竹之间，微风过处，
幽籁天成。不远处，则见道旁依山筑起一片小巧的楼阁，飞檐如凤，画栋雕梁。当
真有如皇宫一般。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"house2",
  "east" : __DIR__"bamboo",
  "north" : __DIR__"valley",
]));
        set("outdoors", "palace");

	set("coor/x",30);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


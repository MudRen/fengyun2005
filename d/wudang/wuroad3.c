
inherit ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
院子里种了无数花草，从名贵的花木到珍贵的药草，各式各样，令人眼花潦乱。
青石小路则由花草中穿过。院子中央有一个八角亭，红色的亭柱，黄色的亭顶。亭
内则是一张石桌，四只石凳。
LONG
	);
	set("exits", ([ 
  		"east" : __DIR__"wuroad4",
  		"west" : __DIR__"wuroad2",
  		"north" : __DIR__"lingyingyan",
	]));
	set("outdoors", "wudang");
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

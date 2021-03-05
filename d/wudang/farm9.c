
inherit ROOM;

void create()
{
	set("short", "庄稼地");
	set("long", @LONG
这是一块刚刚收割过的麦田。地下散落著很多麦穗儿。一个稻草人立在田中，
但却吓不到周围叽叽喳喳的麻雀。它们不停地飞上飞下，争夺著散在地上麦粒。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"farm7",
	]));
	set("objects", ([ 
		__DIR__"npc/bird" : 2,
		__DIR__"npc/dahan" : 1,
	]));
	set("outdoors", "wudang");
	set("coor/x",-20);
	set("coor/y",60);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);

}

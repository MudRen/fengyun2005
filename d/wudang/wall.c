
inherit ROOM;

void create()
{
	set("short", "九曲黄河墙");
	set("long", @LONG
两条夹墙随山势起伏，迥转曲折。高大厚重，使来者走进山门马上感到一种神
秘威严和深邃遥远。传说玄帝幼时在此读书，寓人生修读过程曲折艰辛。
LONG
	);
	set("exits", ([
		"north" : __DIR__"qiongtaiguan",
		"southup" : __DIR__"sansongting",
	]));
	set("outdoors", "wudang");
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

// Room: pomen.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "破门");

	set("long", @LONG
这是间十年前就已该拆掉的房子，看来好像随随便便的一阵风就能将它吹垮。
两扇油漆剥落的大门，也是紧紧关着的，门口还堆着垃圾。你还没有走到大门口，
就闻到一股臭气。
LONG);
	//{{ --- by MapMaker
	set("type","house");
	set("exits",([
	"east":__DIR__"qiongjie5",
	"west":__DIR__"dufang1",
	]) );
	//}}
	set("objects", ([
	__DIR__"npc/qinge" :1,
	]) );
        set("outdoors", "shanliu");
	set("coor/x",5);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

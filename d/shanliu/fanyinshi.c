// Room: fanyinshi.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "梵音寺");

	set("long", @LONG
这座庙就在山坡上的蜜林里。漫天浓雾中，依稀可以分辨出"梵音寺"这三个金
漆已剥落的大字。佛殿上的长明灯一直亮着。但暗淡的灯光却根本照不到高墙外，
远远望过去，只见一片昏黄氤氲，也不知道是烟？是云？还是雾？大门是关着的，
但却关得不紧。一缕缕淡黄色的烟雾，正缥缥缈缈的从门缝里飘出来。
LONG);
	set("exits",([
	"out":__DIR__"nilu6",
	"north":__DIR__"bigyard",
	]) );
	//}}
        set("outdoors", "shanliu");
	set("objects", ([
	__DIR__"npc/tiansisi" :1,
	]) );
	set("coor/x",-2);
	set("coor/y",50);
	set("coor/z",60);
	setup();
	replace_program(ROOM);
}

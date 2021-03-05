// Room: 18.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "大院");

	set("long", @LONG
这是间很宽敞的院子，但似乎很少有人来往，灰尘遍地，蛛网零落院子里弥漫
着一片淡黄色的烟雾，却也不知是烟，还是雾。
LONG);
	//{{ --- by MapMaker
	set("type","indoors");
	set("exits",([
	"north":__DIR__"fodian",
	"south":__DIR__"fanyinshi",
	]) );
        set("outdoors", "shanliu");
	set("coor/x",-2);
	set("coor/y",55);
	set("coor/z",60);

	//}}

	setup();
	replace_program(ROOM);
}

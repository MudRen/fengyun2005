
inherit ROOM;

void create()
{
	set("short", "弯曲小路");
	set("long", @LONG
路的两旁，有各式各样的树木，还有些不知名的花草。在阳光普照的时候，这
山谷一定很美。可是这山谷里是不是也有阳光普照的时候？这满山漫谷的白雾，是
不是也有消散的时候呢？
LONG
	);
	set("exits", ([
                "southwest" : __DIR__"groad2",
                "east" : __DIR__"dating",
	]));
	set("coor/x",-40);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
replace_program(ROOM);

}

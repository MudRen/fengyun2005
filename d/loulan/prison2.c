inherit ROOM;

void create()
{
        set("short", "土牢");
        set("long", @LONG
这间砂土砌的屋子十分阴暗，石壁已经龟裂脱落，原本是古楼兰的平民所住，
因为实在破旧，快活王就以此用来关押一些平常的犯人，屋内肮脏凌乱，也没有床
没有桌椅，几乎除了四壁和一些砂土外就只有屋里关着的两个人了。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"southstrt",
	]));
        set("objects", ([
                __DIR__"npc/wang" : 1,
                __DIR__"npc/zhu" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}

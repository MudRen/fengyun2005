
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
荒山野岭里本没有路，走的人多了，车轱辘印便压出了一条够一辆马车通行的
小路，顺着山中较为平坦地带缓缓向西伸展。向南是一座高耸的绝崖。向西是一片
绿色----大草原就在路的尽头。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"mroad",
  "west" : AREA_GUANWAI"grassland0",
  "south" : __DIR__"cliff",
]));
        set("outdoors", "quicksand");

	set("coor/x",-1130);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


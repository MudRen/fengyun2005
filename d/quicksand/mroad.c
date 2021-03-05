
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
荒山野岭里本没有路，走的人多了，车轱辘印便压出了一条够一辆马车通行的
小路，顺着山中较为平坦地带缓缓向西伸展。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"mfoot",
  "west" : __DIR__"mroad2",
]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/trader" : 2,
        ]) );

	set("coor/x",-1120);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}


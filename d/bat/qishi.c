inherit ROOM;

void create()
{
	set("short", "棋室");
	set("long", @LONG
此处颇为空旷，四壁空无一物，中央放着一个石坪，坪上是一张大理石刻就的
棋盘，盘边各有一个翡翠的小盒，想来是装棋子的。石坪左右各有一个竹垫。
LONG
	);
	set("exits", ([
		"east" : __DIR__"shushi",
            "west" : __DIR__"qinshi",
	]));

	set("objects", ([
        __DIR__"npc/tong2": 1,
    ]));

	set("coor/x",-30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}


inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
只有一个字可以形容这个厅，那就是＂大＂！此厅可以容纳上千人，而且不会
显得拥挤。左手边有一道宽宽的楼梯通向二楼，厅的周围有着两人多高的大门。
LONG
	);
     set("exits", ([
		"east" : __DIR__"zoulang2",
        "north" : __DIR__"d1",
        "up"    : __DIR__"qinshi",
        "west"  : __DIR__"room7",

    ]));
	
	set("objects", ([
		__DIR__"npc/zhao": 1,
	]));

	set("coor/x",-40);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
}

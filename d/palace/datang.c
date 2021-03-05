
inherit ROOM;

void create()
{
        set("short", "大殿");
        set("long", @LONG
这是一间金碧辉煌的大殿，两行蟠龙巨柱，有如巨人般排列在大殿中央。巨柱
之间，又是一道猩红长毯。长毯尽头，石阶再起，上面一张巨桌，桌后一张巨椅，
桌椅俱有蟠龙雕花，闪耀著黄金色的光芒。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"dating",
]));
        set("objects", ([
        __DIR__"npc/master" : 1,
                        ]) );
        set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


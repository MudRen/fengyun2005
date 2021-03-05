inherit ROOM;

void create()
{
        set("short", "阳台");
        set("long", @LONG
这是一个小小的阳台。从这里你可以一直望到山脚。强劲的山风吹在你身上，
让你感到份外的凉爽。真是一个休闲的好去处。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"bedroom",
]));
        set("objects", ([
                __DIR__"npc/pigeon" : 2,
        ]) );

        set("outdoors", "chuenyu");
	set("coor/x",-10);
	set("coor/y",50);
	set("coor/z",30);
	setup();
}


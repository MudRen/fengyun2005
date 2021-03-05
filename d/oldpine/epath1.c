// Room: /d/oldpine/epath1.c

inherit ROOM;

void create()
{
        set("short", "林间小路");
        set("long", @LONG
你现在正走在一条松树林中的小路，这里的松树树干上都有著一些奇怪的记号，
像是被人用刀子划过，小路的西边是一块空地，往东不远可以看到一条山涧，上面
横跨著一座小石桥。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"clearing",
  "east" : __DIR__"epath2",
]));
        set("outdoors", "oldpine");

	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}

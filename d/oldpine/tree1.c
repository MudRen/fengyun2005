// Room: /d/oldpine/tree1.c

inherit ROOM;

void create()
{
        set("short", "大松树上");
        set("long", @LONG
你现在正攀附在一株大松树的树干上，从这里可以很清楚地望见树下的一切动
静，而不被人发觉，似乎是个干偷鸡摸狗勾当的好地方。
LONG
        );
        set("objects", ([
                __DIR__"npc/spy":1 ]) );

        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tree2",
  "down" : __DIR__"clearing",
]));

	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}

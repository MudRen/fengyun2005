// Room: /d/oldpine/spath4.c

inherit ROOM;

void create()
{
        set("short", "下坡道");
        set("long", @LONG
这是一条笔直的坡道，北高南低，道路两旁长满了许多松树，从松林间隐约可
以听到东边传来流水的声音。走到这里，道路已是尽头。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  			"north" : __DIR__"spath3",
		]));
		set("objects", ([ /* sizeof() == 3 */
//  			__DIR__"npc/tall_bandit" : 1,
  			__DIR__"npc/fat_bandit" : 1,
		]));
        set("outdoors", "oldpine");

		set("coor/x",-20);
		set("coor/y",-10);
		set("coor/z",30);
		setup();
        replace_program(ROOM);
}

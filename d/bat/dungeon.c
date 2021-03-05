// dungeon.c

inherit ROOM;

void create()
{
        set("short", "地牢");
        set("long", @LONG
这是一间阴森恐怖的地牢里。似乎有很多在此死去的冤魂飘荡，有许多可怕的
剧毒的血蝙蝠飞来飞去，还有一帮赤胆忠心的侍卫守着，南边墙角处一副大铁栲
上伏着一人，不知是死是活。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south"   : __DIR__"d5",
]));

	set("objects", ([
                __DIR__"npc/xunluo1" : 1,
                __DIR__"npc/dizi" : 2,
                __DIR__"npc/bianfu2" : 1,
                __DIR__"npc/bianfu1" : 1,
		__DIR__"npc/hu" : 1,
	]) );


	set("coor/x",-40);
	set("coor/y",20);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}

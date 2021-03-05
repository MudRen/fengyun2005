// Room: /d/oldpine/spath1.c

inherit ROOM;

void create()
{
        set("short", "林间小路");
        set("long", @LONG
你现在正走在一片松树林中的小路上，小路往北通往一处空地，一株巨大无朋
的松树矗立在空地中央，小路往南是一条长长的下坡道，这条路上足迹很多，显然
常有人经过。
LONG
        );
        set("objects", ([ /* sizeof() == 3 */
  		__DIR__"npc/tall_bandit" : 1,
//  		__DIR__"npc/fat_bandit" : 1,
		]));
        set("outdoors", "oldpine");
        set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"clearing",
  		"south" : __DIR__"spath2",
		]));
        
		set("coor/x",-20);
		set("coor/y",20);
		set("coor/z",30);
		setup();
        replace_program(ROOM);
}

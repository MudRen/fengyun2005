
inherit ROOM;

void create()
{
        set("short", "洞口");
        set("long", @LONG
站在这里，但觉微风佛面，凉爽宜人，你似乎以忘记身在险境。环视四周，一
座刀山赫然而立，山上石山如林，刀上躺著几具正在痛苦挣扎的石像，个个面目如
生。刀山前立有一具判官像，他手中握剑，剑尖斜指刀山。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"realhole",
  "east" : __DIR__"bladem",
]));
        set("objects", ([
        __DIR__"npc/girls" : 2,
                        ]) );

        set("outdoors", "palace");

	set("coor/x",-50);
	set("coor/y",50);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}


// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "五乳峰");
        set("long", @LONG
过达摩洞，便可以到少室绝顶，这里是少室的西峰，山峰陡峭许多少林僧人在
此行功打座，山风阵阵，白云霭霭，对于修行之人最是适合不过。
LONG
        );
        set("exits", ([ 
  "eastdown" : __DIR__"damo",
]));
        set("outdoors", "songshan");
	set("coor/x",63);
	set("coor/y",26);
	set("coor/z",20);
	set("objects", ([
                __DIR__"npc/lama1" : 1,
       ]) );
	setup();
        replace_program(ROOM);
}

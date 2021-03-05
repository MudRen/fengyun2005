// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "碑林");
        set("long", @LONG
这碑林最西，最为出名的当属“[33m大唐天后御制诗书碑[32m”，武则天撰文，王知敬
手书，碑身四龙盘顶，造型别致，碑文正书，笔力遒劲，古来文武相通，到此的武
学名家亦尝赞不绝口。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bei2",
]));
        set("objects", ([
                BOOKS"skill/puti-steps_50" : 1,
		__DIR__"npc/pupil" :2,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-20);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}

// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "鼓楼");
        set("long", @LONG
这里往上便是打鼓楼，巨鼓便在上面。墙上的壁画似乎里面饱含着至深的佛理。
仔细一看，却实在是太模糊了，什么也领悟不了。
LONG
        );
        set("exits", ([ 
  		"up" : __DIR__"gulou4",
  		"down" : __DIR__"gulou2",
	]));
        set("objects", ([
                BOOKS"skill/buddhism_30" : 1,
                __DIR__"npc/monk52" : 1,		
       ]) );
	set("coor/x",-10);
	set("coor/y",-60);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

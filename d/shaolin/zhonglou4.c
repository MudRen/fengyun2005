// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "钟楼");
        set("long", @LONG
这里四周密密严严，丝缝不露，因为在此供奉了一尊明弘治元年的地藏王像，
像中地藏净发，袈裟搭双间，袒前胸，跌坐宝装莲花之上。法像庄严。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"zhonglou5",
  "down" : __DIR__"zhonglou3",
]));
		        set("objects", ([
                __DIR__"npc/monk53_sentry" : 1,   
       ]) );
	set("coor/x",20);
	set("coor/y",-60);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}

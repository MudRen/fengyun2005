
inherit ROOM;

void create()
{
	set("short", "一里四道门");
	set("long", @LONG
不足一华里路程上，建有四座高大山门，一门一景，景致各异，可谓“不尽幽
奇次第逢”。传说，玄帝幼时在此读书，寓人生路途如过山门，要渐第走入高新境
界。
LONG
	);
	set("exits", ([
        "northdown" : __DIR__"sansongting",
		"southup" : __DIR__"jindian",
	]));
	set("objects", ([
                __DIR__"npc/li1" : 1,
		__DIR__"npc/li2" :1 ,
       ]) );
	set("outdoors", "wudang");
	set("coor/x",10);
	set("coor/y",-50);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}

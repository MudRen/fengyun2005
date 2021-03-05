// Room: /d/chuenyu/foot_b_mtn.c

inherit ROOM;

void create()
{
        set("short", "黑松山腰");
        set("long", @LONG
你正艰难的走在唯一通往山顶的小路上。路边堆着很多面目狰狞的巨石。几棵
幼松顽强的从石缝中挤了出来。你在这里可以看到山顶城堡的大致轮廓。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"foot_b_mtn",
  "up" : __DIR__"high_b_mtn",
]));
        set("outdoors", "chuenyu");

	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}


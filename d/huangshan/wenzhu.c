// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "文殊院");
        set("long", @LONG
相传当年普门法师所建，供奉着文殊菩萨，所以叫文殊院，香火盛极一时，可
惜后来因武林正邪势力在玉屏峰决战，殃及文殊院，寺中从此一蹶不振。游人至今
仍可从墙壁的痕迹遥想当年一战的惨烈。
LONG
        );
    set("exits", ([ 
  "southeast"  : __DIR__"yingke",
  "north" : __DIR__"yixian",
	]));
        set("objects", ([
        __DIR__"npc/bing" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-70);
	set("coor/y",10);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}

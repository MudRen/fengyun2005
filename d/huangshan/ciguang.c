// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "慈光阁");
        set("long", @LONG
这是一个用青砖搭成的房子，里面有四根朱漆柱子，除此之外空无一物，原本
该有供游人休息的桌椅已不知去向。房子的墙上开了很多面窗户，透过雕花的窗棂
你可以清楚地看到四周的景色，门大敞着，门上一匾上书“慈光阁”，外面是青石条
铺成的台子。
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"taohua",
]));
        set("objects", ([
                __DIR__"npc/feng" : 1,
		__DIR__"npc/jin" : 1,
       ]) );

        set("indoors", "huangshan");
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}

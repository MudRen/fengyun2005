// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "石笋杠");
        set("long", @LONG
这里石柱林立，形同竹笋，千姿百态。每当黎明破晓，旭日东升，朝
霞遍染群峰，烟云迷漫深壑，神奇瑰丽，慕名而来的无不心悦诚服，赞叹
大自然之鬼斧神工之力。
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"sanhua",
]));
        set("objects", ([
        __DIR__"npc/yan" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-110);
	set("coor/y",10);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}

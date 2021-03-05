// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "一线天");
        set("long", @LONG
这里十分狭长，高达三十余米的石壁紧紧夹峙，一道石阶从中盘环而上，此最
宽处不过两米，窄处只有半米，仰望长空，蓝天一线。虽然少见阳光，石壁上却干
燥凉爽，不见青苔。
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"wenzhu",
  "eastup" : __DIR__"tiandu",
]));
        set("outdoors", "huangshan");
	set("coor/x",-70);
	set("coor/y",40);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}

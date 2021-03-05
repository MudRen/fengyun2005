
inherit ROOM;

void create()
{
        set("short", "石路");
        set("long", @LONG
石路上不见人踪，平滑乾净的石板，看来仿佛终年都有人走动，玉一般暴露在
苍穹之下。往东是一片阴郁的松林，林中似有飞檐楼阁。西边也是一片松林，隐约
有流水之声传来。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"stone",
  "east" : __DIR__"bamboo3",
  "north" : __DIR__"house2",
]));
        set("outdoors", "palace");

	set("coor/x",30);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


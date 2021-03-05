
inherit ROOM;

void create()
{
        set("short", "荒野");
        set("long", @LONG
这是一个无边的荒野地，地势在这里微有起伏，路边的杂草透着灰绿色，不时
有三五成簇的高大树木生长在路边，黄土路在这里向南转了一个弯，转弯处的路边
有一个破乱的砖瓦堆。
LONG
        );
    set("exits", ([ 
  		"south" : __DIR__"road4",
  		"east" : __DIR__"road2",
	]));
	set("objects", ([
		__DIR__"obj/brick" : 1,
	]));   
    set("outdoors", "huashan");

	set("coor/x",5);
	set("coor/y",30);
	set("coor/z",-40);
	setup();
        replace_program(ROOM);
}


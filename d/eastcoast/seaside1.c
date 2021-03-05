// seaside.c
inherit ROOM;
void create()
{
        set("short", "海边");
        set("long", @LONG
转过一个弯，你眼前骤然一宽，无边无际的大海就在眼前了。海风拂面，一洗
过往旅客的一路劳顿。海风清凉，略有点咸味，碧蓝的海水上洁白的浪花滚动，伴
着轻轻的薄雾，仿似戴上了一层迷人的面纱。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"searoad1",
		"north" : __DIR__"village",
	]));
        set("outdoors", "tieflag");

	set("coor/x",1000);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}



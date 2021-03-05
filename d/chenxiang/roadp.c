
inherit ROOM;

void create()
{
        set("short", "荒野");
        set("long", @LONG
这是一个无边的沙砾地，山势到了这里突然间变的无影无踪。地气极干燥，连
风都是暖的。地上的石砾发出一种暗红的颜色，就象是被鲜血染红的一样。再往前
走就是无边无际的大沙漠，一旦进入了就再也没有回头的路了。
LONG
        );
        set("exits", ([ 
  "northwest" : AREA_QUICKSAND"desert2",
  "south" : __DIR__"road",
]));
        set("outdoors", "chenxiang");

	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",-10);
	setup();
}


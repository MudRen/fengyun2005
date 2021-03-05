// work.c
//#include "/feature/damage.c"

inherit ROOM;

void create()
{
        set("short", "石山");
        set("long", @LONG
这里的山峰多是光秃秃的，不同于江南黛青色秀丽的山峦，青灰色的山上只生
长着一些矮小的灌木，有些小山峰甚至被削去的一半，一路过来，山路两侧不时堆
集着刚采下来的巨型石料。一条小路顺着山势蜿蜒的伸向远方，路的尽头是一栋青
色的小石屋。石屋前有一个水缸,想来是供过路的人解渴的.
LONG
        );

    set("resource/water", 1);
    set("liquid/container", "水缸");   	
    set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"work",
		"west" : __DIR__"stonehouse",
	]));
    set("outdoors", "guanwai");

	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "梦笔生花");
        set("long", @LONG
远见松海中耸立着一根独特的石柱，下部直如笔杆，上端酷似笔尖，笔杆和笔
尖之间夹一石缝，更显得象一只自然毛笔，笔尖之上更有一株古松，盘旋曲折，生
机盎然，这就是石笔所生之花。相传当年太白曾在此吟诗，于是怪石也就因“李太
白少时，梦所用之笔头上生花，后天才瞻逸，名闻天下”而被称作“[33m梦笔生花[32m”。
LONG
        );
	set("exits", ([ 
  		"south" : __DIR__"sanhua",
	]));
    set("objects", ([
        __DIR__"obj/meng" : 1,
    ]) );
    
    set("outdoors", "huangshan");
	set("coor/x",-90);
	set("coor/y",10);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}

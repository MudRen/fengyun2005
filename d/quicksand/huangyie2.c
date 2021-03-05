
inherit ROOM;

void create()
{
        set("short", "荒野");
        set("long", @LONG
这是一个无边的沙砾地，山势到了这里突然间变的无影无踪。地气极干燥，连
风都是暖的。地上的石砾发出一种暗红的颜色，就象是被鲜血染红的一样。一条布
满车痕的官道向西方和东方伸展。
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"huangyie0",
  "southwest" : __DIR__"huangyie1",
]));
        set("outdoors", "quicksand");
	set("coor/x",-1005);
	set("coor/y",5);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

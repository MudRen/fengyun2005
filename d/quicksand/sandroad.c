
inherit ROOM;

void create()
{
        set("short", "沙砾小径");
        set("long", @LONG
这里的地上是一种黄褐色，红褐色的石砾镶嵌在细细的黄沙之中，给人以极其
怪异的感觉。这里就是西域与中原的中间地带，城镇的繁华至此再无痕迹，再往西
就是边塞和无边无际的大沙漠。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"huangyie1",
  "west" : __DIR__"saikou",
]));
        set("outdoors", "quicksand");

	set("coor/x",-1020);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


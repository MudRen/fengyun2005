inherit ROOM;

void create()
{
        set("short", "沙岭");
        set("long", @LONG
放眼望去，只有黄沙，无边无际，无穷无尽的黄沙，没有水，没有生命，也
没有希望。此处地远人稀，时常出没的沙盗横行猖獗，沙丘上赫然尸身纵横，血
迹未干。更为可怖的是频繁的沙暴，但见黄沙在风暴中卷舞，唯有沿着岭脊往[33m北[32m
才有出路，若是胡乱瞎闯，这一辈子也不一定走得出去。
LONG
        );
        set("exits", ([ 
		"south" : 	__DIR__"greenland",
		"west" : 	__DIR__"desert6",
		"northeast" : 	__DIR__"mirage",
		"east" : 	__DIR__"desert8",
	]));
        set("outdoors", "loulan");
	set("coor/x",-1085);
	set("coor/y",50);
	set("coor/z",0);
	setup();
}

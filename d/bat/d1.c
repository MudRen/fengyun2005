
inherit ROOM;

void create()
{
	set("short", "黑暗山洞");
	set("long", @LONG
这是一个阴森可怖而且黯淡无光的山洞，一走进来，你倒吸了一口凉气，脑中
一阵晕眩，就什么也想不起来了。
LONG
	);
	set("exits", ([
        "east" : __DIR__"d2",
		"west" : __FILE__,
        "south" : __FILE__,
		"north" : __FILE__,
	]));
	set("coor/x",-40);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}

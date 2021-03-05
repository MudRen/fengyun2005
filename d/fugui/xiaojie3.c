inherit ROOM;

void create()
{
	set("short", "青石小街");

	set("long", @LONG
这是座很宁静的小镇，街道略嫌窄了些，而且有点陡斜。长街很静，只有三两
家的窗户里，还燃着暗淡的灯火。沿街飘过一阵烧鸭的诱人香味，原来西首就是麦
老广的烧腊店，而东面不时有人进进出出，嘴里大都骂骂咧咧，却是附近百里唯一
的“利源当铺”。
LONG);

	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"liyuanpu",
		"west":__DIR__"duckshop",
		"south":__DIR__"xiaojie4",
		"north":__DIR__"xiaojie2",
	]) );
	set("coor/x",20);
	set("coor/y",90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

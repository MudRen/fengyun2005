inherit ROOM;

void create()
{
	set("short", "青石小街");

	set("long", @LONG
这是座很宁静的小镇，街道略嫌窄了些，而且有点陡斜。两旁房屋的构造也很
平凡。长街很静，只有三两家的窗户里还燃着暗淡的灯火。北向而行，路也渐窄，
往西则是如意客栈，高高地打着灯笼。小街东侧则是普通人家。
LONG);
	set("type","street");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"home",
		"west":__DIR__"kezhan",
		"south":__DIR__"xiaojie2",
		"north":__DIR__"shandao9",
	]) );

	set("coor/x",20);
	set("coor/y",110);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

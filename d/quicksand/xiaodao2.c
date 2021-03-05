inherit ROOM;

void create()
{
	set("short", "废旧驿道");
	set("long", @LONG
这是条东西走向的废旧驿道，道上行人寥寥，时近深秋，放眼望去，尽是枯树
败草，朔风肃杀，吹得野草起伏不定，风沙也不时吹进旅人的双眼，也看不清前方
究竟如何。向北的路牌上写着：[33m『富贵山庄』[32m
LONG);
	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
		"north":AREA_FUGUI"yidao1",
		"east":__DIR__"xiaodao1",
		"west":__DIR__"xiaodao3",
	]) );

	set("coor/x",-800);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

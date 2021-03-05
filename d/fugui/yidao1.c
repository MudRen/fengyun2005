inherit ROOM;

void create()
{
	set("short", "废旧驿道");
	set("long", @LONG
这是条南北走向的废旧驿道，道上行人寥寥，时近深秋，放眼望去，尽是枯树
败草，朔风肃杀，吹得野草起伏不定，风沙也不时吹进旅人的双眼，也看不清前方
究竟如何。
LONG);
	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
		"north":__DIR__"yidao2",
	 	"south":AREA_QUICKSAND"xiaodao2",
	]) );

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

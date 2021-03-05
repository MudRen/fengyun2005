inherit ROOM;

void create()
{
	set("short", "废旧驿道");

	set("long", @LONG
驿道越走越窄，几个转弯，竟转到一条大路上来，而一路的风光也陡然一变，
四周草木青翠欲滴，繁花似锦。你不禁长长吸了口气，举目远眺，远处炊烟袅袅，
好象是个集镇。 
LONG);

	set("type","road");
	set("outdoors", "fugui");
	set("exits",([
		"south":__DIR__"yidao4",
		"northeast":__DIR__"qinshilu4",
	]) );
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

inherit ROOM;

void create()
{
	set("short", "青石路");
	set("long", @LONG
这里是一条青石小路，四周地势开阔，放眼望去尽是绿的田，翠的草和清清的
小河。一抬头，便可望见不远处的吉祥小镇了。吉祥镇虽地处中原，但在周围小桥
流水的映托下，也颇有几分江南水乡的神韵。
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"south":__DIR__"qinshilu3",
		"north":__DIR__"xiaojie4",
	]) );
	set("coor/x",20);
	set("coor/y",70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

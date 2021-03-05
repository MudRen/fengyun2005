inherit ROOM;

void create()
{
	set("short", "桃林");
	set("long", @LONG
这里是金大帅每日练功歇息的一片桃林，四处落英缤纷，你仿佛置身于仙境，
真想忘记一切江湖恩怨，在此终老一生。
LONG
	);
	set("type","forest");
	set("outdoors", "fugui");
	set("exits",([
		"southwest":__DIR__"jinshi",
		"northwest":__DIR__"jinmen",
	]) );

	set("objects",([
		__DIR__"npc/dashuai":1,
		__DIR__"npc/guard1c":1,
		__DIR__"npc/guard1b":1,
	]));
	set("coor/x",70);
	set("coor/y",50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

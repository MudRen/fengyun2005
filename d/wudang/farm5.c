
inherit ROOM;

void create()
{
	set("short", "庄稼地");
	set("long", @LONG
一块绿油油的麦田。田中半人高的麦杆儿随风而动，正如江湖中的你，随著江
湖之中汹涌的波涛，四处飘摇。你想到江湖中的无奈,不禁沧然泪下。
LONG
	);
	set("exits", ([
  		"north" : __DIR__"farm1",
  		"south" : __DIR__"farm5",
  		"east" : __DIR__"farm7",
  		"west" : __DIR__"farm5",
	]));
	set("outdoors", "wudang");
	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}

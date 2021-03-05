
inherit ROOM;

void create()
{
	set("short", "松林");
	set("long", @LONG
茂密的松林，不时能见到几只松鼠在树上跳来跳去。虽然只有几丝阳光能透林
而入，却不显得阴森可怖。习习凉风不时迎面吹来，使人浑身舒畅。使你想躺在这
里，睡上一觉。
LONG
	);
	set("exits", ([ 
  		"east" : __DIR__"pine1",
  		"west" : __DIR__"pine2",
  		"north" : __DIR__"pine2",
  		"south" : __DIR__"pine4",
	]));
	set("coor/x",-10);
	set("coor/y",45);
	set("coor/z",-40);
	setup();
	replace_program(ROOM);
}

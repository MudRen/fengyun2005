
inherit ROOM;

void create()
{
        set("short", "岔路口");
        set("long", @LONG
路到这里再向前就分成两条。左面一条，满布著白色的晶石，甚是平坦阅目，
路旁种植两行花草，修剪整齐，香气袭人。往右的一条黑石道路，却曲折地通向一
座阴森黝暗的丛林，道路崎岖坎坷，林中随风吹出阵阵阴湿的臭气。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"white",
  "south" : __DIR__"black",
  "west" : __DIR__"bridge",
]));
        set("outdoors", "palace");

	set("coor/x",-90);
	set("coor/y",100);
	set("coor/z",10);

	setup();
        replace_program(ROOM);
}

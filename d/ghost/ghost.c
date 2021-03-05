
inherit ROOM;

void create()
{
	set("short", "幽灵山庄");
	set("long", @LONG
这像是一个死人的世界。放眼四望，一片空蒙，什么都看不见，白雾忽聚忽散，
是幽灵们在巡行么？北面不远处有一间灰白色的小木屋，在这迷雾般的白云里，一
定要很注意才看得到。
LONG
	);
	set("exits", ([
                "north" : __DIR__"house",
                "west" : __DIR__"bridge",
                "east" : __DIR__"groad1",
	]));
	set("coor/x",-70);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir){
	me->set_temp("marks/know_ghost", 1);
	return 1;
}

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
曲折蜿蜒的小路尽头，迷迷蒙蒙的白雾后面，是一栋形式古老的石屋，里面的
陈设也同样古朴，甚至陈旧得带着种阴森森的感觉。屋子里除了正面靠墙放着一个
黄幔低垂的神龛，其他什么东西都没有。
LONG
	);
	set("exits", ([
                "south" : __DIR__"groad6",
	]));
	set("objects", ([
                __DIR__"npc/master" : 1,
                __DIR__"npc/yexue" : 1,
	]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}

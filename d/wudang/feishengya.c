
inherit ROOM;

void create()
{
	set("short", "飞升崖");
	set("long", @LONG
飞升崖一峰突起，三面绝壁，山脊上有一条小路直达峰巅，跃顶眺望。离天柱
峰已然不远。
LONG
	);
	set("exits", ([
        "westup" : __DIR__"tianzhufeng",
	]));
	set("outdoors", "wudang");
	set("coor/x",20);
	set("coor/y",-70);
	set("coor/z",40);

       	set("objects", ([
        __DIR__"npc/yidianhong": 1,
        ]) );
	setup();

}

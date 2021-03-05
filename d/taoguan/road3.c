
inherit ROOM;

void create()
{
	set("short", "石英岩石阶");
	set("long", @LONG
你正走在一道长长的石英岩阶梯上, 阶梯的两侧种植著一排高耸的松树。抬头
望望东北边那座高耸挺拔的山峰, 云雾飘渺的山顶上矗立著一座雄伟的白色楼阁。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road4",
  "southdown" : __DIR__"road2",
]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",-40);
	setup();
	replace_program(ROOM);
}

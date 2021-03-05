
inherit ROOM;

void create()
{
	set("short", "无名山");
	set("long", @LONG
你面前是一座普通的山峰，一条不算很宽也不算很陡的山道从北面向上延伸着，
左面的山石写着＂无名山＂三个大字。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		  "northup" : __DIR__"road2",
		  "eastdown" : __DIR__"sroad",
	]));
	set("objects", ([ /* sizeof() == 2 */
                __DIR__"npc/tao_1" : 1,
	]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-110);
	set("coor/z",-60);
	setup();
	replace_program(ROOM);
}

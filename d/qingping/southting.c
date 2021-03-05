inherit ROOM;
void create()
{
        set("short", "偏厅");
        set("long", @LONG
厅中甚是整洁，只有一张红木长桌，几张红木矮凳，此时桌上放着许多餐具，
想必是清平弟子饮食之处，几个丫环正在布置，墙上一挂条幅，上书三字"食为先"，
虽平淡，但越发可见主人的心胸早已超凡脱俗。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ting",
  "east" : __DIR__"kitchen",
]));

	set("coor/x",-50);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

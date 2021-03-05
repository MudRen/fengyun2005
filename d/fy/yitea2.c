inherit ROOM;
void create()
{
        set("short", "眉峰聚二楼");
        set("long", @LONG
站在这里，打开小窗就可以看到对面银钩赌坊那在风中摇曳的闪亮银钩。再往
远处看，是一片梅林。梅林中露出一角小楼，正是小李飞刀昔日读书学剑的地方。
梅林无恙，仿佛比几年前开的更胜了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" :   __DIR__"yitea",
]));
        set("objects", ([
	__DIR__"npc/lson" : 1,
	__DIR__"npc/ximen" : 1,
                        ]) );

	set("coor/x",20);
	set("coor/y",-40);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

inherit ROOM;
void create()
{
        set("short", "底舱");
        set("long", @LONG
底舱阴暗潮湿，腐朽扑鼻。和上舱的富丽豪华极不吻合。一盏阴暗的吊烛随着
船身的摇摆而发出吱吱声。四壁阴冷而滑腻，似乎还有水珠的渗出。舱底冰冷，似
乎可以感到湖水的流动。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sr1",
]));

	set("coor/x",-70);
	set("coor/y",15);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}

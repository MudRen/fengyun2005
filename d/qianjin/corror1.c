inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG
每隔五步，左右各一门。门上似有记号，门后似有人声。每隔十步，烛灯一盏，
忽明忽暗。凝神细听，又似乎每户空空。走廊弯弯曲曲，向前伸展，一眼望不到尽
头。每当船身随波摇摆，给人旋晕的感觉。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"corror",
  "west" : __DIR__"corror2",
]));

	set("coor/x",-80);
	set("coor/y",15);
	set("coor/z",0);
        set("objects", ([
        __DIR__"npc/yiku" : 1,
                        ]) );

	setup();
        replace_program(ROOM);
}

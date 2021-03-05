inherit ROOM;
void create()
{
        set("short", "云雨舟甲板");
        set("long", @LONG
湖色淡绿，天色淡蓝。微波荡漾，风景宜人。一声声划拳行酒令，加杂着女人
的娇笑，不时的从船舱中传出。聆耳细听，风声中似乎还加杂着低低的悲泣之声。
与船上的欢声笑语极不融洽。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"boat",
  "north" : __DIR__"boat2",
]));
	set("outdoors","fengyun");
	set("coor/x",-60);
	set("coor/y",15);
	set("coor/z",-1);
	setup();
        replace_program(ROOM);
}

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
  "east" : __DIR__"boat2",
  "south" : __DIR__"tading",
]));
	set("outdoors","fengyun");
        set("objects", ([
        __DIR__"npc/qiudu" : 1,
                        ]) );

	set("coor/x",-65);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

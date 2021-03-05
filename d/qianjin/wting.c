inherit ROOM;
void create()
{
        set("short", "西偏厅");
        set("long", @LONG
厅中一大台，酒肴已设。佳肴异果，罗列满案。酒味醇美，其甘如饴。此时月
色倍明，室中照耀，如同白日。满座芳香，螓首粉面。主客尽情欢笑。再往西则是
一条长长的走廊。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"corror",
  "east" : __DIR__"tading",
]));
       set("objects", ([
        __DIR__"npc/haoke" : 2,
	__DIR__"npc/peijiunu" : 4,
                        ]) );

	set("coor/x",-70);
	set("coor/y",15);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

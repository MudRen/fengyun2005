inherit ROOM;
void create()
{
        set("short", "荡上曲桥");
        set("long", @LONG
荷花荡成葫芦状，在此一曲飞桥连接两岸。至黄昏偶驻，远处灯火万点，间以
星影萤光，错落难辨。深秋时，霜风初起，枫林渐染黄碧，野岸衰柳芙蓉，掩映水
际，芦苇中鸿雁群集，嘹呖干云，哀声动人。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"bridge",
  "west" : __DIR__"grassroom",
]));
        set("objects", ([
        __DIR__"npc/piaoke" : 1,
        __DIR__"npc/piaoke2" :1,
                        ]) );

	set("outdoors","fengyun");
	set("coor/x",-35);
	set("coor/y",10);
	set("coor/z",0);
	set("coor/x",-35);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

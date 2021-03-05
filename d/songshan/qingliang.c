// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "清凉寺");
        set("long", @LONG
已接近山脚，独处一隅，数千株翠柏苍松密密的把寺庙围在当中，即便在夏日
之中，依旧阴凉无比，故此寺名清凉。每年秋天松果盈树，清香扑鼻。此间有松茶
最为吸引人，常有人不远千里来品尝寺中长老调制的松茶。每年春天这里的松针落
得满地，都需要人略做打扫，否则便会积成淤泥。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"lianhua",
]));
	set("coor/x",65);
	set("coor/y",19);
	set("coor/z",-20);
	set("objects", ([
                __DIR__"npc/lama2" : 1,
        ]) );
	setup();
        replace_program(ROOM);
}

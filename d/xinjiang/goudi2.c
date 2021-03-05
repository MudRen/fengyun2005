/*Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "沟底");
        set("long", @LONG
沟底两边长满了老树，即使是盛夏天气，这里的温度也相当低，一阵阵凉风吹
来，暑气全消，时间长了，还会感到寒冷。除了一两声若隐若现的鸟叫之外，四周
真是静，出奇的静，令人毛骨悚然，冷汗凛凛的静。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"goudi",
  "east" :  __DIR__"pubu",
]));
        set("objects", ([
        AREA_OLDPINE"npc/venomsnake" : 2,
	AREA_OLDPINE"npc/bandit" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",30);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

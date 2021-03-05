
inherit ROOM;

void create()
{
        set("short", "流泉");
        set("long", @LONG
穿过松林，前面现出一道清澈的流泉，几座玲珑的假山。流泉来自山上，有如
天绅倒挂，奔腾而下，飞珠溅玉，其声有如仙乐，一阵阵清凉的寒意，沁人心脾。
流泉旁有一间依山而建的山阁。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"gate",
  "east" : __DIR__"stone",
]));
        set("outdoors", "palace");
        set("resource/water",1);
         set("liquid/name","流泉水");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}


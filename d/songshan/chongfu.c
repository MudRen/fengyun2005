// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "崇福宫");
        set("long", @LONG
嵩山乃三教荟萃之地，崇福宫是处道观，道家清幽古朴与佛教的清静无为正是
异根同理。黄瓦明廊，青色墙，都透着不同的风格。从这里北行便是老母洞。东面
便是万丈悬崖，更显得崇福宫之与众不同。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"laomu", 
  "west" : __DIR__"shuyuan",
]));
        set("objects", ([
                __DIR__"npc/daoshi" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",15);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

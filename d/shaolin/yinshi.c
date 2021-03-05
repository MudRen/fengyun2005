// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "隐世楼");
        set("long", @LONG
没想到在少林最无人烟之处，在那竹林之后居然会是这般景色，在青竹，松柏
掩映下，居然悄悄伸出一角飞檐，望去竟然是一竹楼，楼名“隐世”，据传昔年天
下第一高手闯出少林后，为少林千年誉，竟然甘心自缚，隐于少林，从此不出江湖，
难道这楼便是为他所建？
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"zhulin",
]));
        set("objects", ([
                __DIR__"npc/master_xie" : 1,
       ]) );
	set("coor/x",-40);
	set("coor/y",120);
	set("coor/z",20);
	setup();
    //replace_program(ROOM);
}
int invalid_leave(object me)
{
	me->delete_temp("xieask");
	return 0;
}



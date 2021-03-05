//sinny@fengyun.com
//All Rights Reserved
inherit ROOM;
void create()
{
        set("short", "海底");
        set("long", @LONG
漆黑一片，海水冰冷刺骨。
LONG
           );
        set("exits",
            ([
// 	     "east"  : __DIR__"seabutton2",
	    ]));
	set("objects",
 	   ([
 	     __DIR__"npc/shark" : 1,
	    ]));
        set("outdoors", "baiyun");
	set("coor/x",0);
	set("coor/y",-530);
	set("coor/z",-50);
	setup();
	replace_program(ROOM);
}
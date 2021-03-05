// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "藏阁西廊");
        set("long", @LONG
红木长廊，上雕盘龙，精致异常，此处长廊和别处不同，这里的长廊宽阔异常，
路中有明代大石磨盘一个，硕大无朋，据说当年所有僧众所需食物，豆腐都是这个
磨盘所磨。
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"changjing",
]));
        set("objects", ([
                __DIR__"obj/mopan" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}

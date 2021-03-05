// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山门殿角");
        set("long", @LONG
下接山道，上面便是少林正门，有细刻石狮一对，蹲在高大的须弥雕花座上。
给山门增添了一丝活力，石狮左右原来插有高大的旗杆，经历了千年风雨，如今只
剩下旗杆座内的夹杆石了。向上便是少林正门。
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"ent3",
  "west" : __DIR__"shaoyang",
  "up"   : __DIR__"shanmen",
  "eastup" : __DIR__"ye1",
  "westup" : __DIR__"ye2",
]));
        set("objects", ([
                __DIR__"obj/stone" : 1,
		__DIR__"obj/lion" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("NONPC", 1);
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",-20);
	setup();
        replace_program(ROOM);
}

// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "内院");
        set("long", @LONG
一个空旷的黄土院子，院子很大，靠近北面是一道小木门。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"neiyuan2",
  "south" : __DIR__"neimen",
  "east" : __DIR__"guagua",
  "west" : __DIR__"fanting",
]));
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}

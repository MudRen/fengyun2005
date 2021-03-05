// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "三叠泉");
        set("long", @LONG
四周山林清幽，山色如黛，不时传来虫鸣鸟叫之声。不远处一眼泉水从高山下
泄，清澈的泉水流经过三个陡坎而形成三折，每一折处泉水汇成一个小小的水潭，
这就是黄山有名的二奇泉之一“三叠泉”。
LONG
        );
        set("exits", ([ 
  "eastup"  : __DIR__"zuishi",
  "west"	: __DIR__"mingxuan",
]));
        set("objects", ([
                __DIR__"npc/3que" : 1,
       ]) );
	
	set("resource/water", 1);
	set("liquid/name","三叠泉水");
    set("outdoors", "huangshan");
	set("coor/x",-50);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

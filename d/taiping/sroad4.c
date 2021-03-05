#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "红巷");
        set("long", @LONG
红巷在太平镇的南端，过往太平镇的，没有人不知道这条巷子的。小巷里有一
扇红门，红门后有一座鹦鹉楼。远远近近，老老少少，多少人在这里花光了平生的
积蓄，可是走出红巷后从来没有一个人后悔过。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"mroad5",
		"west" : __DIR__"sroad3",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("coor/x",-30);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

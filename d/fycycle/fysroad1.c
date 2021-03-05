// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;
void create()
{
    set("short", "小山坡西面");
    set("long", @LONG
向北再走几里便是风云城，天气好时隐隐约约地还可以看到城里建筑的黑色轮
廓。再向东则是一个光秃秃的小山坡，坡上已被路过的行人踏出了一条黄土路。路
的两边还长了一些半人高的焦黄茅草。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"eastup" : __DIR__"fysroad2",
	"north" :  __DIR__"fysouth",
	"south" : __DIR__"fyroad0",
      ]));
    set("objects", ([
	__DIR__"obj/grass" : 1,
      ]) );
    set("outdoors", "fengyun");

    set("coor/x",0);
    set("coor/y",-380);
    set("coor/z",0);
    setup();
}

void reset()	{
    object con, item, *inv;
    ::reset();
    if( con = present("grass",this_object()))
	if( inv = all_inventory(con))
	    if( !sizeof(inv))
	    {
		item = new( AREA_FY"obj/9whip");
		item->move(con);
	    }	
}





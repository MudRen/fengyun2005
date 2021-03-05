// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "南城厢");
        set("long", @LONG
到处都是灰尘，空气里充满了发霉的味道，令人不敢深呼吸。地下的尘土大约
有一寸厚，一个脚印也没有，只是有一些奇怪的圆孔。这些圆孔从门槛伸延到南墙，
然后就不见了。（艾绒需给杨老太１１两银子） 
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxw2",
]));
        set("objects", ([
        __DIR__"npc/yold": 1,
                        ]) );
	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

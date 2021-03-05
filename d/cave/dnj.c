// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "东南角");
        set("long", @LONG
洞顶很低，钟乳石相当的多，形成一片石林。石林中还有几株紫蘑。紫蘑旁边
居然有几张石凳和一张石台，可以供人休息。洞顶一直在滴水，弄得这里似乎总是
在下雨。
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"ntdm",
  		"west" : __DIR__"tdnd",
	]));
    set("objects", ([
        __DIR__"npc/dinggan": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",10);
	set("coor/y",-14);
	set("coor/z",0);
	setup();
}
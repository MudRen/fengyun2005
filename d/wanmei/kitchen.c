inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "后厨房");
        set("long", @LONG
一盏昏暗的油灯在陈旧的灶台上发出幽弱的光。灶下还有几根半焦的干柴，缓
缓地燃烧着。灶上锅内的山参野鸡汤发出诱人的香味，丝丝白气从锅内的缝中飘出，
令人垂涎欲滴。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"backyard",
]));
        set("resource/water",1);
        set("liquid", ([
            "name": "山参野鸡汤",
            "container":"大锅",
            ]) );
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

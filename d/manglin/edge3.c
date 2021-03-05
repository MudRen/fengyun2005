inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "莽林边缘");
        set("long", @LONG
越走树林越密，树缝中洒下来的阳光也变得斑斑点点。茅草渐厚，灌木丛生，
路径漫灭。吹来的风也越发的阴冷潮湿。远方密林的天空上有几只盘旋的秃鹰，
发出撕心裂肺的叫声，令人毛骨耸然。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"groupe3",
  "east" : AREA_WANMEI"entrance_road"
]));
        set("outdoors", "manglin");
	set("NONPC",1);
	set("coor/x",150);
	set("coor/y",0);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}

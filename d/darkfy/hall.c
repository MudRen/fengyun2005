// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "风云天骄门");
        set("long", @LONG
这是一座古老而神圣的大理石门，大约建于百年前。门上斑斑点点，
风化不堪。传说中是玉皇大帝临凡佳奖天下儿女英雄的地方，凡是被佳
奖的英雄都成为不死之身。一根高耸入云的柱子上刻满了名字：步惊云、
樱花、白宁、灵儿。。。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"ecloud5",
]));
        set("coor/x",50);
        set("coor/y",10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}

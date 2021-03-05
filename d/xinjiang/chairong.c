/* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "柴容堡湖");
        set("long", @LONG
柴容堡湖在白杨沟的北面二十余里处，水平如镜，清可鉴人，盛产鱼蟹。有些
地方的湖水并不深，可以看到湖底的石头和在石缝中穿梭的小鱼，偶尔还有几个气
泡冒出水面，发出＂咕噜咕噜＂的声音。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"tulu3",
  "south" : __DIR__"baiyang",
]));
        set("objects", ([
        AREA_PALACE"npc/fish" : 2,
	AREA_PALACE"npc/shrimp" : 2,
                        ]) );
	//set("no_pk",1);
	
	
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","柴容堡湖水");
        set("liquid/type", "water");
        set("liquid/container","柴容堡湖");
	set("coor/x",10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}

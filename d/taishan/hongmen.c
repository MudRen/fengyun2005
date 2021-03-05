// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","红门宫");
  set("long",@LONG
红木制的门，经历了千年风雨后，依然颜色不改，细看门柱，雕龙刻凤，麒麟，
熊罴，应有尽有，雕工细致至极，可见孔雀抖翎，蜻蜓点水，花鸟鱼虫，山石树木，
在此门上一览无余，进了门后，门阁三重，楼榭数座，筑石起台，白玉雕栏，美不
胜收。往上便是万仙楼。
LONG
  );
  set("exits",([
         "southdown":__DIR__"daizong",
         "up" :__DIR__"wanxian",
	"westup" : __DIR__"puzhao",
	"eastdown" : __DIR__"wangmu",
               ]));
        set("objects", ([
        __DIR__"npc/songzong" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",10);
	setup();
  	replace_program(ROOM);
}

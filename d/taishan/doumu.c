// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","斗母宫");
  set("long",@LONG
凭轩临溪，见中溪之水自上山奔流而下，依次流入三个随山势而降低的小潭，
水势虽不猛急，但是声色俱佳，故有“三潭叠瀑”之称。伴着瑰丽的斗母宫，人与
自然的共同创造融为一体。斗母宫边还有两桥，跨深涧，临中溪，古洞流水，人称
“登仙桥”，无数文人墨客留恋在此，吟下千古绝唱。
LONG
  );
  set("exits",([
         "up":__DIR__"hutian",
         "down" :__DIR__"wanxian",
	"west" : __DIR__"linghan",
	"eastup" : __DIR__"jingshi",
               ]));
        set("objects", ([
        __DIR__"npc/yaren" : 2,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",30);
	setup();
  	replace_program(ROOM);
}

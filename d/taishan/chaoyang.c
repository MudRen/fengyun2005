// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","朝阳洞");
  set("long",@LONG
由五松亭以来，一路松涛夹道，天色昏暗，别有幽趣，石道上怪石横空宛若隧
道，穿山而行，再一路上山，便是天街，由此以上，都是观日，朝阳的好所在，东
去便是梦仙龛。
LONG
  );
  set("exits",([
	"westdown" : __DIR__"wusong",
	"up" : __DIR__"duisong",
	"eastup" : __DIR__"mengxian",
               ]));
        set("objects", ([
        __DIR__"npc/dalao" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",90);
	setup();
  	replace_program(ROOM);
}

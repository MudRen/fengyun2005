// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","放生池");
  set("long",@LONG
放生池由山泉汇集而成。泉水清澈见底，池中鱼可百许头，皆若空游无所依。
看着鱼儿在水中自由自在的游，令人顿生倦意，“人在江湖，身不由己”，此话确
有几分道理。
LONG
  );
  set("exits",([
         "east" :__DIR__"jinggang.c",
         "north":__DIR__"changlang.c",
               ]));
        set("outdoors", "qianfo");
        set("resource/water",1);
	set("liquid",([
            "name":"山泉水",
            "container":"放生池"]));
        set("objects", ([
                __DIR__"npc/lady" : 1,
		__DIR__"npc/badguy":1,
       ]) );

	set("coor/x",-10);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
}


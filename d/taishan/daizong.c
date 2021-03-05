// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","岱宗坊");
  set("long",@LONG
这是岱庙通向泰山的山门，相距泰山不足一里，绿树浓荫，坊身高阔，不由得
令人心生向往，不愧是五岳之首，万山之宗。在这巍峨壮丽的岱宗坊之上，是怎样
的一幅景象呢？
LONG
  );
  set("exits",([
         "south":AREA_DAIMIAO"houzai",
         "northup" :__DIR__"hongmen",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}

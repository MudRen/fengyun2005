// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","碧霞祠");
  set("long",@LONG
碧霞元君是泰山女神，传为东岳大帝之爱女，祠内布局周密，结构严谨，玲珑
精巧，金碧辉煌，祠中供奉一女子，慈眉善目，容颜俏丽，手中拈花，口含微笑，
像前香火不绝，更兼每逢大雾降临，雾潮汹涌，云海迷漫，天仙金阙皆化为那九霄
天宫。
LONG
  );
  set("exits",([
	"west" : __DIR__"nantian",
	"northup" : __DIR__"tianzhu",
	"northeast" : __DIR__"daguan",
	"east" : __DIR__"zhanlu",	
               ]));
	set("coor/x",20);
	set("coor/y",20);
	set("coor/z",120);
	set("objects", ([
               __DIR__"npc/shengcunxiao" : 1,
                        ]) );
	
	setup();
  	replace_program(ROOM);
}

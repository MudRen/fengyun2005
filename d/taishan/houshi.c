// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","后石邬");
  set("long",@LONG
这是泰山之尾，到了这里便无处可登了，地如其名，遍地怪石嶙峋。往下是南
天门，临崖俯视，云海渺茫，细看石上，历代文人骚客，留诗无数，一路苍松万壑
涛，旷达清幽不由得让人豪情顿起，禁不住仰天长啸。
LONG
  );
  set("exits",([
	"south" : __DIR__"nantian",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",30);
	set("coor/z",120);
	setup();
  	replace_program(ROOM);
}

// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","中溪山");
  set("long",@LONG
中溪山是泰山著名三溪--中溪发源地，南侧是千仞陡崖，北翼倾斜，山溪在这
里奔流跌落，构成了为数众多的飞瀑池塘和明沟暗流，塑造了引人入胜的高山流水
景观。
LONG
  );
  set("exits",([
	"south" : __DIR__"yanghuang",
               ]));
        set("objects", ([
        __DIR__"obj/shui" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",30);
	set("coor/z",40);
	setup();
  	replace_program(ROOM);
}

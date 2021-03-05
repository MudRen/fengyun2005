// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","山峰");
  set("long",@LONG
峰回路转眼前突然出现一块平地，然而平地之上拔地而起一座小小山峰，山峰
不高，一条石阶小路盘桓而上直达峰顶，上面有一个红柱黄顶的小亭子。峰下青松
翠柏一片苍绿，一切是那样的宁静。
LONG
  );
  set("exits",([
	"east" : __DIR__"nantian",
	"up" : __DIR__"yueguan",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",120);
	setup();
  	replace_program(ROOM);
}

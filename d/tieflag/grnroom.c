#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",GRN "绿室"NOR);
  set("long",@LONG
一进屋，你忽然发现找不到一个下脚的地方，屋内种满了各式各样的花草，其
中大部分你都叫不上来名字。看着这些翠绿欲滴的草木，你都忍不住想要抚摸一下
它们。
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/grngirl" : 1,
       ]) );
  
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
 }

#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",YEL "黄室"NOR);
  set("long",@LONG
屋内一切器物，桌椅，床铺，包括杯碗勺盆都是用金纸包起来的，甚至连四壁
都贴着金纸，令人不由得想起纸醉金迷这句话来。
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/yelgirl" : 1,
       ]) );
  
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
 }

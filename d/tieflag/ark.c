#include <room.h>  
inherit ROOM;
void create()
{
  set("short","方舟");
  set("long",@LONG
黑纱中光线灰黯，香烟氤氲，一位夫人盘膝坐在蒲团之上。蒲团边有一香炉。
烟云从香炉上冉冉升起，充满了整个房间。

LONG
  );
  	set("exits/out" ,__DIR__"outboat");
    set("objects",([
    	__DIR__"npc/jiayi" : 1,
		__DIR__"obj/coffin": 1,
    ]) );

	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",0);
	setup();
	
 }



int reset(){
	object coffin;
	
	coffin = present("coffin", this_object());
	if (coffin)
	if (!random(10) && coffin->query_temp("been_get"))
		coffin->delete_temp("been_get");
		
	::reset();
}
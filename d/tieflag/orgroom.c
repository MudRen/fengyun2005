#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",HIY "橙室"NOR);
  set("long",@LONG
这里简直就是一家酒楼，不，应该说是酒楼的贮藏室，墙上挂满了金黄的烧鸡，
烤鹅，板鸭。按理说，贮藏烧鸡的地方应该很臭，可是这里不但不臭，空气中还飘
着美酒的香气。香气来自墙角的一只大木桶，不用说，里面装的一定不是一般的酒
LONG
  );
  	set("exits/center" ,__DIR__"shishi");
        set("objects", ([
                __DIR__"npc/orggirl" : 1,
       ]) );
  
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
 }

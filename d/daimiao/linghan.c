#include <room.h>
inherit ROOM;

void create()
{
  set("short","汉柏凌寒");
  set("long",@LONG
汉柏院一带原来是柏林地，传说汉武帝封泰山时在这里植了二千多株柏树，历
经二千多年今尚存五株。古柏枝身扭结上耸，若虬龙蟠旋，虽然肤剥心枯，却又继
生新枝，苍古葱郁，被列为岱庙八景之一的『汉柏凌寒』。
LONG
  );
  	set("exits",([
        	 "north":__DIR__"hanbai",
         	
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",20);
	set("coor/y",-45);
	set("coor/z",0);
	setup();
  	
}

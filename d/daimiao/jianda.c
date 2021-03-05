#include <room.h>
inherit ROOM;

void create()
{
  set("short","见大门");
  set("long",@LONG
西侧的门称为“见大”，意思是在山下看，泰山仰之弥高，又目睹其大。门上
均建有精巧玲珑的角楼。斗拱出三翘四，彩绘点金飞龙，富丽堂皇，气势非凡，大
有凌空欲飞之势。
LONG
  );
  	set("exits",([
        	 "north":__DIR__"w_wall_1",
         	 "east":  __DIR__"w_yemen",
         	 "up":	__DIR__"jiaolou1",
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-30);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
  	
}

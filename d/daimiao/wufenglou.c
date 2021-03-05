#include <room.h>
inherit ROOM;

void create()
{
  set("short","五凤楼");
  set("long",@LONG
岱庙周围城墙共有八门，除两侧的掖门外，其余门上皆建有门楼。正阳门上的
是五凤楼，黄瓦盖顶，点金彩绘，富丽堂皇，高耸巍峨。
LONG
  );
  	set("exits",([
        	 "down":__DIR__"zhengyan",       
        	 "east": __DIR__"jiaolou2",  	
        	 "west": __DIR__"jiaolou1",
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",10);
	setup();
  	
}

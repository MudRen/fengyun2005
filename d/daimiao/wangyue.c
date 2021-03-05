#include <room.h>
inherit ROOM;

void create()
{
  set("short","望岳楼");
  set("long",@LONG
望岳楼与正阳门的五凤楼法式相同，黄瓦明廊，红柱隔扇，如云端琼阙。站在
望岳楼上，可仰望巍巍泰岱与天齐，可眺瞻天门云梯隐天际。
LONG
  );
  	set("exits",([
        	"down":__DIR__"houzai",
        	"west" :__DIR__"jiaolou3.c",
         	"east" :__DIR__"jiaolou4.c",       	
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",10);
	setup();
  	
}

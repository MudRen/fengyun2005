#include <room.h>
inherit ROOM;

void create()
{
  set("short","东掖门");
  set("long",@LONG
正阳门两侧的小门是掖门。岱庙大院四周围筑城墙，周环三里。庙有八个门，
南向五门，中为正阳，两侧为掖门；掖门两侧，东为仰高，西为见大。东门名东华，
又称青阳；西门名西华，又称素景，北门叫厚载。
LONG
  );
  	set("exits",([
        	"west":__DIR__"zhengyan",
         	"east":__DIR__ "yanggao",
         	"southwest": __DIR__"daimiao",
        ]));
        set("objects", ([
        
        ]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",20);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
  	
}

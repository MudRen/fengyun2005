//mac's zhengyan
#include <room.h>
inherit ROOM;
void create()
{
  	set("short","正阳门");
  	set("long",@LONG
正阳门是岱庙的正门，也是帝王之门：“正阳者，南方日中之气也”。这是一
座典型的道观大门，两丈高的青砖围墙隔开了外界的喧嚣。高大厚实的朱漆大门令
人肃然起敬，小屋殿顶下一块大匾：正阳门。
LONG
  );
  	set("exits",([
        	"north":__DIR__"peitian",
         	"south":__DIR__"daimiao",
         	"west" :__DIR__"w_yemen",
         	"east" :__DIR__"e_yemen",
         	"up":	__DIR__"wufenglou",
               ]));
        set("objects", ([
		__DIR__"npc/guard2c":	2,
                
       	]) );
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}

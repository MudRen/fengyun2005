#include <room.h>
inherit ROOM;

void create()
{
  set("short","三灵侯殿");
  set("long",@LONG
配天殿东边是三灵侯殿，祭祀的是周朝谏官唐宸、葛雍、周武三人。传说宋真
宗东封泰山时，在岱顶南天门见到了这三位神人，于是就加封为“三灵侯”，后来
在这里建此大殿祭祀。
LONG
  );
  	set("exits",([
        	 "west":__DIR__"peitian",
         	 "east":__DIR__"hanbai",
         	 "south":__DIR__"guaying",
        ]));
        set("objects", ([

       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
  	
}

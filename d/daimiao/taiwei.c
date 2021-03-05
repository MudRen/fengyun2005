#include <room.h>
inherit ROOM;

void create()
{
  set("short","太尉殿");
  set("long",@LONG
配天殿的西配殿叫太尉殿，是专门祭祀唐代名人杜崇的。此人在唐武宗的会昌
年间曾被任命为中书侍郎。大殿周围东西两侧有碑碣二十多块。其中最著名的是东
南方的宋代《宣和重修东岳庙记碑》和西南方的《大宋封东岳天齐仁圣帝碑》，两
座丰碑东西对峙，高大雄伟，龟趺螭首，气势非凡。
LONG
  );
  	set("exits",([
        	 "east":__DIR__"peitian",
         	 "west":__DIR__"yuhua",
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
  	
}

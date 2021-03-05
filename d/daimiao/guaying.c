#include <room.h>
inherit ROOM;

void create()
{
  set("short","挂印封侯");
  set("long",@LONG
这棵生长在路东侧的古柏树传说是汉柏，苍郁挺拔，枝繁叶茂。主干与侧枝的
交接处之上长了一个奇特的树瘤，越看越像一只顽皮的猴子在猴头猴脑地到处张望，
胸前还挂着一个似圆似方的印牌，这就是岱庙八景之一的『挂印封侯』(猴)。由这
儿再往西就是汉柏院。
LONG
  );
  	set("exits",([
        	 "north":__DIR__"sanling",
         	
        ]));
        set("objects", ([
                
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",10);
	set("coor/y",-45);
	set("coor/z",0);
	setup();
  	
}

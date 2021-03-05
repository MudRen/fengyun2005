inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC"圣母峰山脚"NOR);

	set("long", @LONG
方到圣母峰下，纵目四望，但见冰川交错，俨若银龙，又是另外一番奇景。冰
川的冰层，虽因受到初夏的阳光，已有部分融化，汇成小川流下。山顶的雪花，一
片一片轻飘飘落下，就好像水晶末一般，由于太阳光的折射和散射，整个冰层都变
成浅蓝色的透明体，端的是奇丽万状，难以形容。但最美丽的地方，往往也就是最
危险的地方，如果你执意前行，很可能便会死无葬身之地。
LONG);

	set("type","street");
	set("exits",([
		"up":__DIR__"maze1",
		"northeast":__DIR__"birdroad3",
	]) );
    
     set("item_desc", ([
        	"小川": 		"水流湍急，从这儿是没法游上去的。\n",
        	"water": "水流湍急，从这儿是没法游上去的。\n",
        	"river": "水流湍急，从这儿是没法游上去的。\n",
     ]));
    
    set("outdoors", "guanwai");
	set("coor/x",-30);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

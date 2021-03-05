#include <room.h>
inherit ROOM;

void create()
{
  set("short","环廊");
  set("long",@LONG
天贶殿两侧有环廊百间，与仁安门两侧的东西神门相连，廊下绘有十殿阎罗七
十二司，西廊内，陈列着五十多块汉画像石。其中有车马步卒、二龙交璧、龙虎车
骑、狩猎拜谒、人物行列、斗座百戏、双龙日月、莲花五铢等图案，都是出土于泰
山附近的汉墓中。
LONG
  );
  	set("exits",([
        	 "east":__DIR__"xibei",
         	 "south":__DIR__"chuxun",
        ]));
        set("objects", ([
                __DIR__"npc/di" : 1,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-20);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
  	
}

#include <room.h>
inherit ROOM;

void create()
{
  set("short","东环廊");
  set("long",@LONG
天贶殿两侧有环廊百间，与仁安门两侧的东西神门相连，廊下绘有十殿阎罗七
十二司，东廊内由北向南陈列着历代名碑十九块，其中最著名的有清时《秦泰山刻
石》的复制碑、《汉故卫尉卿衡府君之碑》、《汉故谷城长荡阴令张君表颂》、
《晋任城太守夫人孙氏之碑》及《太极图》和《望岳诗碑》等。
LONG
  );
  	set("exits",([
        	 "west":__DIR__"dongbei",
         	 "south": __DIR__"chuihua",
        ]));
        set("objects", ([
        	__DIR__"npc/weaponer":	1,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",20);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
  	
}

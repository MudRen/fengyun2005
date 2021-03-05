#include <room.h>
inherit ROOM;

void create()
{
  	set("short","西华门");
  	set("long",@LONG
岱庙四周高墙围绕，庙东有“东华门”，又称“青阳”，西有“西华门”，又
称“素景”，是按天神五帝东为青帝、西为白帝而命名的。
LONG
  );
  	set("exits",([
		"north": __DIR__"w_wall_2",
         	"south":__DIR__"w_wall_1",
         	"east": __DIR__"chuxun",
        ]));
        set("objects", ([
		__DIR__"npc/guard2a": 2,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",-30);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
  	
}

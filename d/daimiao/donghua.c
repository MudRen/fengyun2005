#include <room.h>
inherit ROOM;

void create()
{
  	set("short","东华门");
  	set("long",@LONG
岱庙四周高墙围绕，庙东有“东华门”，又称“青阳”，西有“西华门”，又
称“素景”，是按天神五帝东为青帝、西为白帝而命名的。
LONG
  );
  	set("exits",([
         	"south":__DIR__"e_wall_1",
         	"west": __DIR__"chuihua",
         	"north": __DIR__"e_wall_2",
        ]));
        set("objects", ([
                __DIR__"npc/guard2b": 2,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
  	
}

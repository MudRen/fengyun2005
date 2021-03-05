
#include <room.h>
inherit ROOM;
void create()
{
  	set("short","汉柏院");
  	set("long",@LONG
汉柏院座东朝西，大门上悬挂着云纹大匾，上书“炳灵门”，因院内原有炳灵
殿，内供泰山神的三太子炳灵王而得名。另外，院内还有古柏五株，传为汉武帝东
封时所植，所以此院旧称“炳灵宫”，今称“汉柏院”。
LONG
  );
  	set("exits",([
         	"west":__DIR__"sanling",
         	"north": __DIR__"hanbaiting",
         	"south": __DIR__"linghan",
        ]));
        set("objects", ([
        	__DIR__"npc/tian":	1,
        
       	]) );
	set("coor/x",20);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}

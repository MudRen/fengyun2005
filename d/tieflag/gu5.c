inherit DOOR_ROOM;
#include <room.h>
void create()
{
        set("short", "大堂");
        set("long", @LONG
明丰高轩，玉壁生辉。堂中一处白玉塌，塌前一张矮几上散置着四时鲜花、各
色佳果。四处明洁如镜，你的身影都映入画中。
LONG
        );

        set("exits", ([ /* sizeof() == 4 */ 
        "eastup" : __DIR__"gu4", 
		"south" :__DIR__"goldroom",	
        ])); 
        set("objects",([
       		__DIR__"npc/yinbin2" : 1,
//       		__DIR__"npc/cat1" : 1,
       	]) );
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",10);
	setup();
      	create_door("eastup","door","玉门","westdown",DOOR_CLOSED);
}


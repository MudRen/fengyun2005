//mac's fudong.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","千佛崖");
  set("long",@LONG
禅院南侧峭壁陡立，俗称“千佛崖”，现残留隋开徒皇年间摩崖造像六十余尊。
崖下有龙泉、极乐、黔娄三洞，亦雕有大小佛像。千佛山因此崖成名。洞壁和峭壁
上的佛像已逾千座。禅宗佛教自曹溪慧能后，禅徒只以道相授受，多岩居穴处，这
大约便是禅寺初创时始祖的居室。
LONG
  );
  	set("exits",([
        	 "west" :__DIR__"jinggang",
        	 "north":__DIR__"changlang2",
       	]));
        set("objects", ([
        	 __DIR__"npc/master3" : 1,
       	]) ); 
	set("coor/x",10);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}

//mac's chansi.c
#include <room.h>

inherit ROOM;

void create()
{
  set("short","兴国禅寺");
  set("long",@LONG
青石砌起的山门上刻着：[33m兴国禅寺[32m。寺内飘来的阵阵佛香让登山的游人香客精神
一振，回荡的钟鼓之音又给人一种肃穆的感觉。山门两旁的对联格外引人注目：
[0;1;31m
		暮鼓晨钟  惊醒世间名利客
		经声佛号  唤回苦海梦迷人		
[0m
LONG
  );
        set("objects", ([
                __DIR__"npc/bonze2" : 2,
		__DIR__"npc/greeting" : 2,
       	]) );
  	set("exits",([
         	"southdown":__DIR__"fudi.c",
         	"north"    :__DIR__"jinggang.c"
       ]));
   
        set("outdoors", "qianfo");
	set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}

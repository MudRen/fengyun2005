inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "高楼");
        set("long", @LONG
高楼，楼上有窗，窗前有月，月下有花。
　　花是蔷薇，月是明月。
　　微微的灯火在桌上摇动，月光从窗外照进来，照在你身上。
　　你身边不但有蔷薇，还有个被蔷薇刺伤的人。
LONG
        );
        set("exits", ([ 
		"down" : __DIR__"teashop",
	]));
        set("objects", ([
	]) );
        set("coor/x",-20);
        set("coor/y",20);
        set("coor/z",10);
	set("map","zbwest");
	setup();
}



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/


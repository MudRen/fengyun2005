#include <ansi.h>
inherit ROOM;

int room_check(object room);

void create()
{
        set("short", "大明湖底");
        set("long", @LONG
什么也看不见，一片黝黑的水底．．．
LONG
        );
    	set("exits", ([
        	"up" : __DIR__"lake",
    	]) );
    	set("no_fly", 1);
	set("coor/x",20);
	set("coor/y",80);
	set("coor/z",-60);
	set("underwater",100);
	set("water_damage",20);
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

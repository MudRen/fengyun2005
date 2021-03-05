
inherit ROOM;

void create()
{
        set("short", "白云楼");
        set("long", @LONG
白云楼依山而建，是观主师徒修行之处，一幢三层的小楼，和构筑宏伟的太清
上清殿相较，直如蝼蚁之比大象。二楼是丁白云的三个弟子清风、清漪、清濯的居
室，四下里一尘不染，陈设简陋，廊道上供奉一尊香炉，终日里青烟袅袅。
LONG
        );
        set("exits", ([ 
  		"down" : __DIR__"book_room1",
  		"up": 	__DIR__"book_room3",
	]));
        set("objects", ([
		__DIR__"obj/desk2" : 1,
		__DIR__"npc/taolord1" : 1,
		
 	]) );

	set("no_lu_letter",1);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",15);
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


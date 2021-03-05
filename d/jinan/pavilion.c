#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", WHT"烟水相忘"NOR);
	set("long", @LONG
精致石雕的桌子，紫漆描花的扶栏，空气里仿佛还弥散着浅浅淡淡的清茶
香。天空中云霞变幻，整座烟水亭笼罩着一层温暖的晕黄，只是风雨杳杳，岁
月流年，小小的亭台还在，当年相对小酌，誓言着永不分离的人，却早已散落
开去，相忘在海角天涯了。
LONG
	);
	set("exits", ([ 
  "out" : __DIR__"bridge4",
]));
	set("no_fight",1);
        set("objects", ([
//        __DIR__"npc/zhou" : 1,
//        __DIR__"npc/song" : 1,
// 回家了..
//        __DIR__"npc/thief" : 1,
// 搬家了..
        __DIR__"npc/zhuxiang" : 1,

                        ]) );
	set("coor/x",100);
	set("coor/y",120);
	set("coor/z",10);
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

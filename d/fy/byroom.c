#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "白云行馆");
    set("long",  @LONG
风悄悄地吹过，白云慵懒地游荡在蓝天上，坐落在白云深处的就是世人所向的
天庭。这座洗礼池后的清雅小筑与远在海外的白云岛没有任何联系，来往之人也少
见江湖中的粗豪之气，倒是常常有个喜著嫩黄衣裳，俊美无度的年轻人会在几个随
从的簇拥之下到此小住。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"ponder",
      ]));
    set("indoors", "fengyun");
	set("no_fight",1);
    set("objects", ([
	__DIR__"npc/princess": 1,
	__DIR__"npc/eunuch": 1,
	__DIR__"npc/duangonggong":1,
      ]) );

    set("coor/x",40);
    set("coor/y",100);
    set("coor/z",0);
    set("map","fynorth");
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

#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "小木屋");
        set("long", @LONG
一间空空荡荡，破破落落的小木屋，显然是临时清理出来供人歇息；
向屋角看去，一个身著曳地长裙的女子正坐在摇摇欲朽的木椅上望着窗外
，她身边小几摆放着一瓶开得正艳的山茶，搭建屋子的木板已经腐烂，空
气中理应飘荡着霉腐的气味，却只有那一瓶山茶的清香。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"village2",
	]));
	set("item_desc", ([
	 ]));
	set("coor/x",900);
	set("coor/y",60);
	set("coor/z",0);
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

